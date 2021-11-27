#if 0
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <bitset> 
#include <thread>
#include <functional>
#include <queue>

using namespace std;

void* process(void* arg)
{
	printf("thread 0x%x working on task %d\n ", std::this_thread::get_id(), *(int*)arg);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("task %d is end\n", *(int*)arg);

	return NULL;
}
using myfunc = std::function<void* (void*)>;
using thread_task_t = struct
{
	myfunc func;
	void* arg;
};


int const BIT_SET_NUMS = 100;

class Thread_pool
{
public:

	Thread_pool() = default;
	Thread_pool(int min_thr_num, int max_thr_num, int queue_max_size) {
		this->min_thr_num = min_thr_num;
		this->max_thr_num = max_thr_num;
		this->queue_max_size = queue_max_size;

		this->busy_thr_num = 0;
		this->live_thr_num = min_thr_num;
		this->queue_size = 0;
		this->queue_front = this->queue_rear = 0;
		this->shutdown = false;

		threads = new thread[this->max_thr_num];//开辟空间
		task_queue = new thread_task_t[this->queue_max_size];

		for (int i = 0; i < this->min_thr_num; i++) {
			//threads[i] = std::thread(thread_process);//调用成员函数必须使用对象指针
			threads[i] = std::thread(&Thread_pool::thread_process, this);
			mybit[i] = 1;
			cout << "第" << i << "个线程启动成功\n";
		}
		adjust_tid = std::thread(std::bind(&Thread_pool::thread_adjust, this));
	}

	void add(thread_task_t& task)
	{
		do {
			std::unique_lock<std::mutex> mylock(mtx);
			while (this->taskque.size() == this->queue_max_size && !this->shutdown) {//队列满了
				this->queue_not_full.wait(mylock);
			}
			if (this->shutdown)
				mylock.unlock();
			if (this->taskque.front().arg != nullptr) {
				//delete (this->task_queue[this->queue_rear].arg);//这个崩溃
				this->taskque.front().arg = nullptr;
			}

			//添加任务到队列 
			//this->task_queue[this->queue_rear].func = task.func;
			//this->task_queue[this->queue_rear].arg = task.arg;
			//this->queue_rear = (this->queue_rear + 1) % this->queue_max_size;
			//this->queue_size++;

			this->taskque.push(task);

			queue_not_empty.notify_one();//添加完任务后，队列不为空，唤醒线程池中 等待处理任务的线程

		} while (false);
	}

private:
	void thread_process() {
		
		while (true) {

			std::unique_lock<std::mutex> mylock(mtx);
			do {
				//std::unique_lock<std::mutex> mylock(mtx);
				//没有任务，那处理任务的进程应该阻塞在queue_not_empty上
				while (this->taskque.size() == 0 && !this->shutdown) {

					this->queue_not_empty.wait(mylock);

					//清除指定数目的空闲线程，如果要结束的线程个数大于0，结束线程
					if (this->wait_exit_thr_num > 0) {
						this->wait_exit_thr_num--;

						if (this->live_thr_num > this->min_thr_num) {
							this->live_thr_num--;


							return;
						}
					}
				}
			} while (false);



			if (this->shutdown) {
				//mylock.unlock();
				return;
			}
			/*从任务队列里获取任务, 是一个出队操作*/

			auto task = taskque.front();
			taskque.pop();

			//thread_task_t task;

			//task.func = this->task_queue[this->queue_front].func;
			//task.arg = this->task_queue[this->queue_front].arg;

			//this->queue_front = (this->queue_front + 1) % this->queue_max_size;
			//this->queue_size--;

			queue_not_full.notify_one();//通知可以有新的任务添加
			mylock.unlock();

			//执行任务
			this->thread_counter.lock();
			this->busy_thr_num++;
			this->thread_counter.unlock();
			task.func(task.arg);

			//任务 结束处理
			this->thread_counter.lock();
			this->busy_thr_num--;
			this->thread_counter.unlock();
		}
	}

	void thread_adjust() {
		while (!this->shutdown) {
			this_thread::sleep_for(chrono::seconds(this->sleep_dafault_time));//定时对线程池管理
			int que_size = 0, live_num = 0, busy_num = 0;

			do {
				std::lock_guard<std::mutex> mylock(mtx);
				que_size = this->taskque.size();//任务个数
				live_num = this->live_thr_num;//存活线程个数
			} while (false);

			do {
				std::lock_guard<std::mutex> mylock(thread_counter);
				busy_num = this->busy_thr_num;
			} while (false);

			//创建新线程  法则可以自己设置
			//任务数大于最小线程池个数, 且存活的线程数少于最大线程个数时 如：30>=10 && 40<100*/
			if (que_size >= MIN_WAIT_TASK_NUM && live_num < this->max_thr_num) {
				do {
					std::lock_guard<std::mutex> mylock(mtx);
					int add = 0;
					for (int i = 0; i < this->max_thr_num && add < DEFAULT_THREAD_VARY; i++) {
						if (mybit[i] != 0)
							continue;
						threads[i] = std::thread(&Thread_pool::thread_process, this);
						mybit[i] = 1;
						add++;
						this->live_thr_num++;
					}
				} while (false);
			}

			//销毁额外线程
			//算法：忙线程X2 小于 存活的线程数 且 存活的线程数 大于 最小线程数时*/
			if (busy_num * 2 < live_num && live_num > this->min_thr_num) {
				do {
					std::lock_guard<std::mutex> mylock(mtx);
					this->wait_exit_thr_num = DEFAULT_THREAD_VARY;//10
				} while (false);

				for (int i = 0; i < DEFAULT_THREAD_VARY; i++) {
					queue_not_empty.notify_all();
				}
			}
		}//while 
	}
	volatile bool m_stop;

private:
	mutex mtx;//锁住线程池类的
	mutex thread_counter;//锁住 忙线程个数 

	condition_variable queue_not_full;//任务队列不为满的时候，还可以添加任务，满的时候添加任务线程阻塞
	condition_variable queue_not_empty;//任务队列不为空，处理任务，空的时候处理任务线程阻塞

	std::thread* threads;//存放线程池的每一个线程的数组
	std::thread adjust_tid;//管理线程


	thread_task_t* task_queue;

	queue< thread_task_t> taskque;



	int min_thr_num;                    /* 线程池最小线程数 */
	int  max_thr_num;                    /* 线程池最大线程数 */
	int live_thr_num;                   /* 当前存活线程个数 */
	int busy_thr_num;                   /* 忙状态线程个数 */
	int wait_exit_thr_num;              /* 要销毁的线程个数 */

	int queue_front;                    /* task_queue队头下标 */
	int queue_rear;                     /* task_queue队尾下标 */
	int queue_size;                     /* task_queue队中实际任务数 */
	int queue_max_size;                 /* task_queue队列可容纳任务数上限 */

	bool shutdown;                       /* 标志位，线程池使用状态，true或false */

	int sleep_dafault_time = 10;
	int const MIN_WAIT_TASK_NUM = 10;
	int const DEFAULT_THREAD_VARY = 10;

	bitset<BIT_SET_NUMS> mybit;

};

int main()
{
	Thread_pool thread_pool(3, 100, 100);
	int num[20]{ 0 }, i = 0;
	for (i = 0; i < 20; i++) {
		num[i] = i;
		cout << "add task: " << i << endl;
		thread_task_t task;
		task.func = process;
		task.arg = &i;
		thread_pool.add(task);
	}

	system("pause");
	return 0;
}
#endif
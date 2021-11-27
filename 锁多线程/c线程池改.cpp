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

		threads = new thread[this->max_thr_num];//���ٿռ�
		task_queue = new thread_task_t[this->queue_max_size];

		for (int i = 0; i < this->min_thr_num; i++) {
			//threads[i] = std::thread(thread_process);//���ó�Ա��������ʹ�ö���ָ��
			threads[i] = std::thread(&Thread_pool::thread_process, this);
			mybit[i] = 1;
			cout << "��" << i << "���߳������ɹ�\n";
		}
		adjust_tid = std::thread(std::bind(&Thread_pool::thread_adjust, this));
	}

	void add(thread_task_t& task)
	{
		do {
			std::unique_lock<std::mutex> mylock(mtx);
			while (this->taskque.size() == this->queue_max_size && !this->shutdown) {//��������
				this->queue_not_full.wait(mylock);
			}
			if (this->shutdown)
				mylock.unlock();
			if (this->taskque.front().arg != nullptr) {
				//delete (this->task_queue[this->queue_rear].arg);//�������
				this->taskque.front().arg = nullptr;
			}

			//������񵽶��� 
			//this->task_queue[this->queue_rear].func = task.func;
			//this->task_queue[this->queue_rear].arg = task.arg;
			//this->queue_rear = (this->queue_rear + 1) % this->queue_max_size;
			//this->queue_size++;

			this->taskque.push(task);

			queue_not_empty.notify_one();//���������󣬶��в�Ϊ�գ������̳߳��� �ȴ�����������߳�

		} while (false);
	}

private:
	void thread_process() {
		
		while (true) {

			std::unique_lock<std::mutex> mylock(mtx);
			do {
				//std::unique_lock<std::mutex> mylock(mtx);
				//û�������Ǵ�������Ľ���Ӧ��������queue_not_empty��
				while (this->taskque.size() == 0 && !this->shutdown) {

					this->queue_not_empty.wait(mylock);

					//���ָ����Ŀ�Ŀ����̣߳����Ҫ�������̸߳�������0�������߳�
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
			/*������������ȡ����, ��һ�����Ӳ���*/

			auto task = taskque.front();
			taskque.pop();

			//thread_task_t task;

			//task.func = this->task_queue[this->queue_front].func;
			//task.arg = this->task_queue[this->queue_front].arg;

			//this->queue_front = (this->queue_front + 1) % this->queue_max_size;
			//this->queue_size--;

			queue_not_full.notify_one();//֪ͨ�������µ��������
			mylock.unlock();

			//ִ������
			this->thread_counter.lock();
			this->busy_thr_num++;
			this->thread_counter.unlock();
			task.func(task.arg);

			//���� ��������
			this->thread_counter.lock();
			this->busy_thr_num--;
			this->thread_counter.unlock();
		}
	}

	void thread_adjust() {
		while (!this->shutdown) {
			this_thread::sleep_for(chrono::seconds(this->sleep_dafault_time));//��ʱ���̳߳ع���
			int que_size = 0, live_num = 0, busy_num = 0;

			do {
				std::lock_guard<std::mutex> mylock(mtx);
				que_size = this->taskque.size();//�������
				live_num = this->live_thr_num;//����̸߳���
			} while (false);

			do {
				std::lock_guard<std::mutex> mylock(thread_counter);
				busy_num = this->busy_thr_num;
			} while (false);

			//�������߳�  ��������Լ�����
			//������������С�̳߳ظ���, �Ҵ����߳�����������̸߳���ʱ �磺30>=10 && 40<100*/
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

			//���ٶ����߳�
			//�㷨��æ�߳�X2 С�� �����߳��� �� �����߳��� ���� ��С�߳���ʱ*/
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
	mutex mtx;//��ס�̳߳����
	mutex thread_counter;//��ס æ�̸߳��� 

	condition_variable queue_not_full;//������в�Ϊ����ʱ�򣬻����������������ʱ����������߳�����
	condition_variable queue_not_empty;//������в�Ϊ�գ��������񣬿յ�ʱ���������߳�����

	std::thread* threads;//����̳߳ص�ÿһ���̵߳�����
	std::thread adjust_tid;//�����߳�


	thread_task_t* task_queue;

	queue< thread_task_t> taskque;



	int min_thr_num;                    /* �̳߳���С�߳��� */
	int  max_thr_num;                    /* �̳߳�����߳��� */
	int live_thr_num;                   /* ��ǰ����̸߳��� */
	int busy_thr_num;                   /* æ״̬�̸߳��� */
	int wait_exit_thr_num;              /* Ҫ���ٵ��̸߳��� */

	int queue_front;                    /* task_queue��ͷ�±� */
	int queue_rear;                     /* task_queue��β�±� */
	int queue_size;                     /* task_queue����ʵ�������� */
	int queue_max_size;                 /* task_queue���п��������������� */

	bool shutdown;                       /* ��־λ���̳߳�ʹ��״̬��true��false */

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
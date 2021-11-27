#if 0
#include <iostream>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <bitset>
#include <unordered_map>
#include <cassert>

using namespace std;


class Thread_pool {
public:
	using MutexGuard = std::lock_guard<std::mutex>;
	using UniqueLock = std::unique_lock<std::mutex>;
	using Thread = std::thread;
	using ThreadID = std::thread::id;
	//using Task = std::function<void()>;
	using myfunc = std::function<void* (void*)>;
	using Task = struct {
		myfunc func;
		void* args;
	};
	


	Thread_pool() = default;

	explicit Thread_pool(size_t maxThreads) :
		quit(false),
		curr_num(0),
		idle_num(0),
		max_num(maxThreads)
	{

	}
	//不允许进行拷贝构造
	Thread_pool(const Thread_pool&) = delete;
	Thread_pool& operator=(const Thread_pool&) = delete;

	~Thread_pool() {
		{
			MutexGuard guard(mtx);
			this->quit = true;
		}
		cv.notify_all();
		for (auto& elem : threadmap) {
			assert(elem.second.joinable());
			elem.second.join();
		}
	}

	size_t threadsNum()const {
		MutexGuard guard(mtx);//如果底下不加mutable，会出错
		return curr_num;
	}

	void add(myfunc func, void* args) {
		MutexGuard guard(mtx);
		assert(!quit);//如果quit为真，！quit为假，出现断言错误

		Task task;//task结构体 
		task.func = func;
		task.args = args;
		taskque.emplace(task);

		if (this->idle_num > 0) {
			this->cv.notify_one();
		}
		else if (this->curr_num < max_num) {
			Thread t(&Thread_pool::work, this);
			assert(threadmap.find(t.get_id()) == threadmap.end());//确保新线程不是之前存在过的

			threadmap[t.get_id()] = std::move(t);
			//threadmap[t.get_id()] = t;//无法执行
			++curr_num;
		}

	}




private:

	bool quit;//是否退出
	size_t curr_num;
	size_t idle_num;
	size_t max_num;//分别是当前进程数，空闲进程数，最大进程数

	static constexpr size_t               WAIT_SECONDS = 2;

	mutable std::mutex mtx;//为了threadsNum（）const  而加mutable
	std::condition_variable cv;
	std::queue<Task> taskque;
	std::queue<ThreadID> finishedThreadIDs;
	std::unordered_map<ThreadID, Thread> threadmap;


	void work()
	{
		while (true) {
			Task task;
			{
				UniqueLock uniquelock(mtx);
				++this->idle_num;
				auto hastimedout = cv.wait_for(uniquelock,
					std::chrono::seconds(WAIT_SECONDS),
					[this]() {  return quit || !this->taskque.empty(); }
				);

				--idle_num;
				if (taskque.empty()) {
					if (quit) {
						--curr_num;
						return;
					}
					if (hastimedout) {
						--curr_num;
						joinfinishedThread();
						finishedThreadIDs.emplace(std::this_thread::get_id());
						return;
					}
				}//taskque.empty()
				//task = std::move(taskque.front());
				task = taskque.front();//不加也不会出错
				taskque.pop();
			}//{}
			task.func(task.args);
			
		}//while (true)
	}

	void joinfinishedThread() {
		while (!finishedThreadIDs.empty()) {
			//auto id = std::move(finishedThreadIDs.front());
			auto id = finishedThreadIDs.front();
			finishedThreadIDs.pop();

			auto iter = threadmap.find(id);

			assert(iter != threadmap.end());
			assert(iter->second.joinable());

			iter->second.join();
			threadmap.erase(iter);
		}
	}

};
constexpr size_t Thread_pool::WAIT_SECONDS;

void* print(void *)
{
	cout << "hello\n" << endl;
	return nullptr;
}
int main()
{
	Thread_pool pool(10);
	for (int i = 0; i < 10; i++) {
		pool.add(print, nullptr);
	}


	return 0;
}
#endif
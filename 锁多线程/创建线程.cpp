#if 0
#include "wjxHeaders.h"
#include <mutex>


std::mutex mtx;
void hhhh()
{
	cout << "function called\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void hhhh2(int a)
{
	cout << "a=" << a << endl;
}
void func()
{
	int i = 0;
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		cout << "hello,world," << i++ << endl;;
	}
}
void func1(int idx)
{
	while (true) {
		mtx.lock();
		cout << "hello,world," << idx << endl;
		mtx.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}

}
void func2()
{
	while (true) {
		mtx.lock();
		cout << "hello,world,"  << endl;
		mtx.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
}
int main()
{
	//std::thread t1(hhhh);
	//t1.join();

	//std::thread t2(hhhh2,10);

	//t2.join();

#if 0 //线程开辟在堆上---？？通过
	std::thread* thread = new std::thread(func);

	if (thread->joinable())
		thread->join();
	delete thread;
#endif

#if 0 //线程数组---》通过
	std::thread threads[5];
	for (int i = 0; i < 5; i++) {
		threads[i] = std::thread(func1, i);
	}
	for (int i = 0; i < 5; i++) {
		if (threads[i].joinable())
			threads[i].join();
	}
#endif 


#if 1 //开辟在堆上的线程数组--》通过
	std::thread * threads = new thread[5];
	for (int i = 0; i < 5; i++) {
		//threads[i] = std::thread(func1, i);
		threads[i] = std::thread(func2);
	}
	for (int i = 0; i < 5; i++) {
		if (threads[i].joinable())
			threads[i].join();
	}
	delete[] threads;
#endif
	system("pause");
	return 0;
}


#endif
#if 0
#include <iostream>
#include  <semaphore> 
#include <thread>
#include <ctime>
using namespace std;
/*
不同于 std::mutex ， counting_semaphore 不捆绑到执行线程——能在不同于释放信号量的线程获取该信号量。
能同时进行 counting_semaphore 上的所有操作而无需联系到任何特定的执行线程，除了不能同时执行，但能在一个不同的线程上执行析构函数。

信号量亦常用于发信/提醒而非互斥，通过初始化该信号量为 ​0​ 从而阻塞尝试 acquire() 的接收者，直至提醒者通过调用 release(n) “发信”。
在此方面可把信号量当作 std::condition_variable 的替用品，通常它有更好的性能。
*/
/*
Mutex:

is a key to a toilet. One person can have the key - occupy the toilet -at the time. 
When finished, the person gives(frees)the key to the next person in the queue. Officially:"
Mutexes are typically used to serialise access to a section of re-entrant code that cannot be executed concurrently by more than one thread.
A mutex object only allows one thread into a controlled section , 
forcing other threads which attempt to gain access to that section to wait until the first thread has exited from that section."

Mutex 是厕所的钥匙，一个人有了钥匙后，就会占据厕所，当它用厕所结束了以后，这个人就把钥匙交给等待厕所的队列中的下个人
Semaphore:

is the number of free identical toilet keys.Example,say we have four toilets with identical locks and keys.
The semaphore count - the count of keys - is the count value is decremented as people are coming in.
If all toilets are full. there are no free keys left, the semaphore count is 0.
NOw,when one person leaves the toilet, semaphore is increased to 1(one free key),and given to the next person in the queue.
Officially:"A semaphore restricts the number of simultaneous users of a shared resource up to a maximum number.
Threads can request access to the resource (decrementing the semaphore),and can singnal that they have finished using the resource (incrementing the semaphore)."

信号量是 空闲的（可供使用的） 厕所的钥匙，如果有4个厕所有相同的锁和钥匙
信号量的数值 ，也就是钥匙的数量，当有人进入厕所，这个数值（信号量的数值）会增加
如果所有厕所都满了，就没有空闲的钥匙剩下了，也就是信号量的值是0，当前一个人离开厕所，信号量就增长到1
然后把钥匙给队列中的下一个人。




二元信号量 binary_semaphore   和 锁 std::mutex：
1.初始化锁，相当于给锁一个数值1
2.加锁，相当于减减操作，阻塞线程
	一个线程拿到锁，锁的值相当于是0，此时另外一个线程如果尝试加锁，再减就为负了，无法拿到锁，所以阻塞在加锁位置
3.解锁，相当于加加操作，唤醒阻塞在锁上的线程
	原来的另一个线程因为尝试加锁阻塞时，此时锁的值变成1，此时加锁（值减1）能够成功


要是二元信号量，我们应该初始化为1
binary_semaphore has_product(1)

acquire() 减少内部计数器 或阻塞到能这样（不能减少内部计数器时，就阻塞，直到能减少）
release() 增加内部计数器 并除阻 获取者（有线程阻塞时，因为acquire调用无法完成，release调用就可以了，这样阻塞的线程就能解除阻塞了）




*/




//using binary_semaphore = std::counting_semaphore<1>;//后者可以被若干个线程获得。
binary_semaphore has_product(1); //前者只能被一个线程获得，
int arr[5];

void producer()
{
	int i = 0;
	srand(time(nullptr));
	while (true) {
		has_product.acquire();//
		arr[i] = rand() % 100 + 1;
		cout << "-----------------producer:arr=" << arr[i] << endl;
		has_product.release();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		i = (i + 1) % 5;
	}
	return;
}
void consumer()
{	
	int i = 0;
	srand(time(nullptr));
	while (true) {
		has_product.acquire();
		cout << "--consumer:arr[i]=" << arr[i] << endl;
		arr[i] = 0;
		has_product.release();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		i = (i + 1) % 5;
	}
	return;
}



int main(void)
{


	std::thread t_producer(producer);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::thread t_consumer(consumer);
	if (t_producer.joinable())
		t_producer.join();
	if (t_consumer.joinable())
		t_consumer.join();

	system("pause");
	return 0;

}
#endif

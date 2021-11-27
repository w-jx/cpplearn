#if 0
#include <iostream>
#include <semaphore>
#include <thread>
#include <ctime>
#include <array>

using namespace std;
/*
����c++ 20ʵ�ֵ�������������ģ��
���룺-std=c++2a
//gcc9.3��ʱ����֧��

*/
std::counting_semaphore prod(5);
std::counting_semaphore consu(0);

std::array<int, 5> arr;
void producer()
{
    srand(time(nullptr));
    int i = 0;

    while (true) {
        prod.acquire();
        arr[i] = rand() % 10;
        cout << "in producer,arr[" << i << "]=" << arr[i] << endl;
        consu.release();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i = (i + 1) % 5;
    }

}
void consumer()
{

    int i = 0;

    while (true) {
        consu.acquire();
        cout << "--in consumer,arr[" << i << "]=" << arr[i] << endl;
        prod.release();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i = (i + 1) % 5;
    }
}

int main()
{

    std::thread t_prod(producer);
    std::thread t_consu(consumer);

    if (t_prod.joinable())
        t_prod.join();
    if (t_consu.joinable())
        t_consu.join();


    return 0;
}
#endif
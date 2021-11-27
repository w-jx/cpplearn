#if 0
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <ctime>
#include <mutex>

using namespace std;

//����shared_mutex ʵ�ֶ�д�� c++17֧��

std::shared_mutex mtx;

int counter = 0;//ȫ�ֱ���

void th_write(int idx)
{
    int t = 0;
    while (true) {
        do {
            std::lock_guard<std::shared_mutex> mylock(mtx);
            t = counter;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("--write:%d,%lu:counter:%d,++counter=%d\n", idx, std::this_thread::get_id(), t, ++counter);
        } while (false);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}

void th_read(int idx)
{

    while (true) {
        do {
            std::shared_lock<std::shared_mutex> mysharedlock(mtx);
            //mtx.lock_shared();//������
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("--read:%d,%lu:counter:%d\n", idx, std::this_thread::get_id(), counter);
           // mtx.unlock_shared();
        } while (false);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{

    std::thread t[8];//8���߳�

    for (int i = 0; i < 3; i++) {
        t[i] = std::thread(th_write, i);//3��д
    }
    for (int i = 3; i < 8; i++) {
        t[i] = std::thread(th_read, i);//5����
    }
    for (int i = 0; i < 8; i++) {
        if (t[i].joinable())
            t[i].join();
    }

    return 0;

}
#endif
#if 0
#include <iostream>
#include <thread>
#include <ctime>
#include <mutex>

#include <condition_variable>
using namespace std;

//��������ʵ�ֵ������� ������ģ�� 
struct msg
{
    msg() = default;
    msg(int _num) : num(_num), next(nullptr) {}
    struct msg* next;
    int num;
};
struct msg* head;

std::mutex mtx; //��
std::condition_variable has_product;

void producer()
{
    srand(time(nullptr));
    while (true)
    {
        msg* mp = new msg(rand() % 1000); //ģ����������
        printf("---proc,mp->num=%d\n", mp->num);
        do{
            std::unique_lock<std::mutex> mylock(mtx);
            mp->next = head;
            head = mp;
        } while (false);

        has_product.notify_one(); //���������������������߳�
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 3));
    }
}
void consumer()
{
    srand(time(nullptr));
    while (true)
    {
        {
            msg* mp = nullptr;
            //std::lock_guard<std::mutex> mylock(mtx);
            
            do{
                std::unique_lock<std::mutex> mylock(mtx);
                if (head == nullptr)
                    has_product.wait(mylock);
                //���������˵��û��������
                mp = head;
                head = mp->next;
            } while (false);
            printf("====================---consumer,mp->num=%d\n", mp->num);
            delete mp;
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 3));
        }
    }
}
int main()
{

    std::thread t_producer(producer);
    std::thread t_consumer(consumer);

    if (t_producer.joinable())
        t_producer.join();
    if (t_consumer.joinable())
        t_consumer.join();

    return 0;
}
#endif
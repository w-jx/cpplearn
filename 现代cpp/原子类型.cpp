#include "../wjxHeaders.h"
#include <thread>
atomic<int> a{0},b{0};

int valueSet(int){
    int t = 1;
    a = t;
    b = 2;
    return 0;
}
int GetValue(int){
    cout<<"a:"<<a<<",b:"<<b<<"\n";
    return 0;
}

int main()
{
    thread t1(valueSet,0);
    thread t2(GetValue,0);
    t1.join();
    t2.join();
    cout<<"Main a:"<<a<<",b:"<<b<<endl;
}
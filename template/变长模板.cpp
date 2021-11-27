#include "../wjxHeaders.h"


template <typename ... ARGS>
void fun(ARGS ... args)
{
    cout<<sizeof...(args)<<endl;
}



template<typename T>
void print(const T& t) {
    cout<<t<<"\n";
}
template<typename T,typename...Args>
void print(const T&t,Args...args) {
    cout<<t<<"\n";
    print(args...);//递归解决，利用模板推导机制    
}

//sizeof...运算符，可以确定到底有几个参数
void test()
{
    // fun(1,2,3,4,5);
    // fun(1,2,3);
    print(1,2,"aa",'g');
}


int main()
{
    test();
}
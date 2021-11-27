#include "wjxHeaders.h"

//在左值右值.cpp没有说完的，这边继续举一些例子

/*
总结结论：
1.如果不会更改参数值得，例如向vector.push_back(const value_type& val)
添加const value_type&
2.如果有需要更改参数值的
就用万能引用
template<typename T>
void func(T && val)

好处是调用的时候，不管左值，右值都能直接调用
func(a)
func(2)


*/


void func(int a) 
{
    cout<<"func:"<<a<<endl;
}

void funcref(int &a) 
{
    cout<<"funcref:"<<a<<endl;
}
void funcConstref(const int &a) 
{
    cout<<"funcConstref:"<<a<<endl;
    //a+=1;//弊端:const 以后无法进行修改了
}
//对左值，添加std::move，对右值，直接调用，可以更改
void funcrightref(int && a) 
{
     cout<<"funcrightref:"<<a<<endl;
     a+=10;
}
//引用折叠原理 只有T && && -> T && ,其余情况得到的都是T &
template<typename T>
void funcallref(T && a) 
{
     cout<<"funcallref:"<<a<<endl;
     a=0;
}
int main()
{
    int a = 10;
    func(a);//
    func(2);//不管是左值，右值都是可以的

    //funcref(a);
    //funcref(2);//无法通过编译
    funcConstref(a);
    funcConstref(2);

    //funcrightref(a);//无法通过编译
    funcrightref(std::move(a));
    funcrightref(2);
    cout<<"aftera+10,a:"<<a<<endl;

    funcallref(a);
    funcallref(2);
    cout<<"after a=0,a:"<<a<<endl;
}
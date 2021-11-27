#include <iostream>

//场景：已经有基类Base,和派生类D1，有虚函数f1()
//现在需要新加一个派生类D2和f2()
//实际上f1，f2行为类似，可以抽象放在基类中

class Base
{
public:
    virtual void f() ;
};

void Base::f()
{
    //f默认实现
}

class D1 : public Base
{
};
class D2 : public Base
{
};
//现在派生类D3，它的f()实现完全不同，如果忘记定义f,这是一场灾难
class D3 : public Base
{
};

void test()
{
    Base *b = new D3;
    b->f(); //这个f()操作是错误的f
    //我们应该要在D3中重新定义f
    //1.可以定义为纯虚函数，这样抽象类不能实例化
    //如果D3不实现f,D3也不能初始化

    //定义为虚函数后，想要默认实现
    //方法1
    /*
        在base:
            protected:
                void f_impl();
        然后在D1,D2中
        void D1::f(){
            f_impl()
        }
        D3重新实现
        void D3::f(){
            //f实现
        }
    */
   //方法2：直接在base 的纯虚函数中实现
    /*

        void D1::f()
        {
            Base::f();
        }

    */

}



int main()
{
}
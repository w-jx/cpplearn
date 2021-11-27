#include <iostream>

//场景
//有 Base类和虚函数f()
//派生类D1,D2都有相同的行为，所以在base类中实现了即可，用缺省实现
//现在需要加D3派生类，它的f()行为和缺省不一样
//很容易遗漏在D3中实现f()
/*
解决方法:
    方法1:
        纯虚函数+缺省实现,见纯虚函数缺省实现.cpp
    方法2:
        class Base {
                public:
                    virtual void fun1() const;
                    virtual void fun2(int x);
                    virtual void fun3() &;
                    void fun4() const;    // is not declared virtual in Base
                };
                
                class Derived: public Base {
                public:
                    virtual void fun1();        // declared const in Base, but not in Derived.
                    virtual void fun2(unsigned int x);    // takes an int in Base, but an unsigned int in Derived
                    virtual void fun3() &&;    // is lvalue-qualified in Base, but rvalue-qualified in Derived.
                    void fun4() const;        
                };

    C++11 中的 override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错。
    纯虚函数      => 继承的是：接口 (interface)
　　普通虚函数   => 继承的是：接口 + 缺省实现 (default implementation)
　　非虚成员函数 =>继承的是：接口 + 强制实现 (mandatory implementation)

    不要重新定义一个继承自基类的非虚函数 (never redefine an inherited non-virtual function
    声明需要重写的函数后，加关键字 override

*/
int main()
{

}
#if 0
#include "wjxHeaders.h"
#pragma pack(8)
class A
{
private:
    static int s_var; // 不影响类的大小
    const int c_var;  // 4 字节
    int var;          // 8 字节 4 + 4 (int) = 8
    char var1;        // 12 字节 8 + 1 (char) + 3 (填充) = 12
public:
    A(int temp) : c_var(temp) {} // 不影响类的大小
    ~A() {}                      // 不影响类的大小
    virtual void f() { cout << "A::f" << endl; }

    virtual void g() { cout << "A::g" << endl; }

    virtual void h() { cout << "A::h" << endl; } // 24 字节 12 + 4 (填充) + 8 (指向虚函数的指针) = 24
};

void test01()
{
    A a(10);
    /*
    在网上的C++在线编译器,结果是24
    本机运行结果是16
    */
    cout << sizeof(a) << endl;//结果为16
}
int main()
{
	test01();
}
#endif
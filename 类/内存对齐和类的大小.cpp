#if 0
#include "wjxHeaders.h"
#pragma pack(8)
class A
{
private:
    static int s_var; // ��Ӱ����Ĵ�С
    const int c_var;  // 4 �ֽ�
    int var;          // 8 �ֽ� 4 + 4 (int) = 8
    char var1;        // 12 �ֽ� 8 + 1 (char) + 3 (���) = 12
public:
    A(int temp) : c_var(temp) {} // ��Ӱ����Ĵ�С
    ~A() {}                      // ��Ӱ����Ĵ�С
    virtual void f() { cout << "A::f" << endl; }

    virtual void g() { cout << "A::g" << endl; }

    virtual void h() { cout << "A::h" << endl; } // 24 �ֽ� 12 + 4 (���) + 8 (ָ���麯����ָ��) = 24
};

void test01()
{
    A a(10);
    /*
    �����ϵ�C++���߱�����,�����24
    �������н����16
    */
    cout << sizeof(a) << endl;//���Ϊ16
}
int main()
{
	test01();
}
#endif
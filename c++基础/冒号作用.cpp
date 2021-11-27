#if 0
#include <iostream>
#include <vector>
using namespace std;
/*

除了我已知的用法，还有的作用
1.放在全局函数前，表示是全局
	比如说有一个std::max函数，我们自己定义了一个max函数，名称相同
	用::max代表使用的是全局的，而不是标准模板库的
2.表示引用成员函数或者变量，作用域成员运算符，相当于.
*/
class A
{
public:
	A() {};
	A(int _p1, int _p2, string _p3);
	int p1;
	int p2;
	string p3;
};
A::A(int _p1, int _p2, string _p3)//类内声明，类外定义
{
	this->p1 = _p1;
	this->p2 = _p2;
	this->p3 = _p3;
}
void test01()
{
	cout << "i am wenjx\n";
}
int main(void)
{
	::test01();//冒号放在全局函数前表示是全局函数
	A a(1,2,"aaa");//新建成员a
	cout << "a.p1=" << a.p1 << endl;//传统写法
	::A* newobj = new A;
	newobj->p1 = 1;
	newobj->p2 = 2;
	newobj->p3 = "wenlaoshi";

	cout << newobj->p3 << endl;
	//cout << "a.p1=" << a::p1 << endl;//报错的
	//cout << "a.p1=" << A::p1 << endl;//非静态成员引用必须要和特定成员相对，报错
	system("pause");
	return 0;
}
#endif
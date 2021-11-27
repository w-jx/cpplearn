#if 0
#include <iostream>
using namespace std;
/*
静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
静态成员变量
1.所有对象共享同一份数据
2.编译阶段分配内存
3.类内声明,类外初始化

静态成员函数
1.所有对象共享同一个函数
2.静态成员函数只能访问静态成员变量
*/

class Person
{

public:
	static int m_A; //静态成员变量

	//静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

private:
	static int m_B; //静态成员变量也是有访问权限的
};
int Person::m_A = 10;//类外初始化
int Person::m_B = 10;
//静态成员变量的访问方式
void test01()//
{
	//1.通过对象
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl;//两个输出都是200
	cout << "p2.m_A = " << p2.m_A << endl;

	

	//2.通过类型
	cout << "m_A = " << Person::m_A << endl;
//	cout << "m_B = " << Person::m_B << endl;//私有成员无法访问



}

void test02()//
{

}

void test03()//
{

}

void test04()//
{

}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	test01();//静态成员变量的访问方式
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
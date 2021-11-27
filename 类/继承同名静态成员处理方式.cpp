#if 0
#include <iostream>
using namespace std;
/*
问题：继承中同名的  静态成员   在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致
访问子类同名成员   直接访问即可
访问父类同名成员   需要加作用域
*/
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};
int Base::m_A = 100;//静态成员类内声明,类外初始化
class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;
//测试
void test01()//
{
	cout << "通过对象访问:" << endl;
	Son s;
	cout << "Son.m_A:" << s.m_A << endl;
	cout << "base.m_A:" << s.Base::m_A << endl;

	cout << "通过类名访问" << endl;
	cout << "son.m_A:" << Son::m_A << endl;
	cout << "Base,m_A:" << Base::m_A << endl;
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

	test01();//测试
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
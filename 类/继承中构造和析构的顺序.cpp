#if 0
#include <iostream>
using namespace std;

/*
子类继承父类后，当创建子类对象，也会调用父类的构造函数
问题：父类和子类的构造和析构顺序是谁先谁后？

结论:先调用父类构造函数,再调用子类构造函数,再调用子类析构函数,再调用父类析构函数
构造函数父类先,子类后,析构顺序和构造顺序相反
*/
class Base
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};
class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son()
	{
		cout << "Son析构函数!" << endl;
	}

};
//测试构造 析构顺序
void test01()//
{
	Son s;
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

	test01();//测试构造 析构顺序
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
#if 0
#include <iostream>
using namespace std;

/*
对象的初始化和清理 用构造函数 和析构函数来解决,对象的初始化和清理工作
是编译器强制要我们做的额事情,因此如果我们不提供构造和析构,编译器会提供,编译器提供的构造函数和析构函数
是空实现

构造函数:创建对象时为对象的成员属性赋值,构造函数由编译器自动调用,无须手动调用
1.构造函数可以有参数,因此可以发生重载
2.程序在调用对象的时候会自动调用构造,无需手动调用,而且只会调用一次

析构函数:主要作用在于对象销毁前系统自动调用,执行一些清理工作
1析构函数不可以有参数,因此不可以发生重载
2.程序在对象销毁前会自动调用析构,无须手动调用,而且只会调用一次


*/
class Person
{
public:
	//无参(默认)构造函数
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}
	Person(int age)//有参构造函数
	{
		this->m_Age = age;
	}
	Person(const Person& p)//拷贝构造函数
	{
		this->m_Age = p.m_Age;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
private:
	int m_Age;

};
//构造函数 和析构函数的自动调用介绍
void test01()//
{
	Person p;
}
//构造函数的分类  和调用
void test02()//
{
	//调用方式 1.括号法
	Person p1(10);//注意1:调用无参构造函数不能加括号,加了括号编译器会认为是函数声明

	//显式法
	Person p2 = Person(10);//Person(10)是匿名对象,当前行结束,立刻析构
	Person p3 = Person(p2);

	//隐式转换
	Person p4 = 10;//等同于 Person p2 = Person(10);
	Person p5 = p4;//等同于 	Person p5 = Person(p4);


	Person p6(p5);//注意,不能利用拷贝构造函数,初始化匿名对象,编译器认为是对象声明
	//这种方式,p6没有m_Age属性,说明没有创建对象成功
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

	//test01();//构造函数 和析构函数的自动调用介绍
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
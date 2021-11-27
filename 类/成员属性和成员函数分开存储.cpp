#if 0
#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		//mA = 0;
	}
	//非静态成员变量占对象空间
	//int mA;	
	//int mC;
	//静态成员变量不占对象空间
	static int mB;
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		//cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};
class Student
{
 ~Student(){}
};
//类的大小
void test01()//
{
	cout << sizeof(Person) << endl;//结果是4,因为里面有int m_A;
	//添加一个int mB,结果变成8,全部注释,结果是1

	cout << sizeof(Student) << endl;//结果是1
	/*
	C++标准规定类的大小不能为0，空类的大小为1，当类中不包含非静态成员变量和虚函数时，该类对象的大小也为1.
	声明该类型的实例的时候，它必须在内存中占有一定的空间,如果是0的话,
	那么student s1;s1不占有内存空间,显然是不合理的
	1.student 空类 大小是1
	2.添加virtual ~Student(){},变成4,去了virtual关键字是1
	*/
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

	test01();//类的大小
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
#if 0
#include <iostream>
using namespace std;

/*
成员函数后加const后我们称为这个函数为**常函数**
常函数内不可以修改成员属性
成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象:声明对象前加const称该对象为常对象
常对象只能调用常函数

*/
class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void ShowPerson() const {
		//const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->m_A = 100; //但是this指针指向的对象的数据是可以修改的

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
		cout << "showPerson()调用" << endl;
	}

	void MyFunc()  {
		//mA = 10000;
		this->m_A = 10000;
		cout << "MyFunc()调用" << endl;
	}

public:
	int m_A;
	mutable int m_B; //可修改 可变的
};
//const 修饰对象 常对象
void test01()//
{
	const Person person; //常量对象  
	cout << person.m_A << endl;//可以访问成员变量的值,但是无法修改
	//person.m_A = 200;//报错,常对象无法修改成员变量的值


	person.m_B = 100;//可以修改加了mutable关键字的变量

	person.ShowPerson();//常对象只能调用常函数
	//person.MyFunc();

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

	test01();//const 修饰对象 常对象
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
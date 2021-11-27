#if 0
#include <iostream>
using namespace std;
/*
当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
访问子类同名成员   直接访问即可 访问父类同名成员   需要加作用域

*/
class Teacher
{
public:
	void func()
	{
		cout << "teacher,func()" << endl;
	}
	Teacher() { m_Age = 0; }
	int m_Age;
};
class Student :public Teacher
{
public:
	void func()
	{
		cout << "student,func()" << endl;
	}
	Student() { m_Age = 10; }
	int m_Age;
};
void test01()//
{
	Student s;
	cout << "s.m_Age = " << s.m_Age << endl;//子类直接访问
	cout << "teacher.m_Age = " << s.Teacher::m_Age << endl;//父类需要加作用域

	s.func();//子类直接访问
	s.Teacher::func();//非静态成员引用必须要和一个对象相对应,所以Teacher::func()不行
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

	//test01();//
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
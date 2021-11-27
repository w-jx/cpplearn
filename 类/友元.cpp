#if 0
#include <iostream>
using namespace std;

/*
友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元
*/
class Student
{
	friend void func(Student& s);//告诉编译器,这是一个全局友元函数可以访问类中的私有内容
	friend class VisitStudent;//告诉编译器VisitStudent是Student类的友元,可以访问Student的私有内容
public:
	Student() {};
	Student(int a,int b):m_Height(a),m_Age(b) {}
	int m_Height;
private:
	int m_Age;
};
//类做友元
class VisitStudent
{
public:
	VisitStudent() { student(); }
	void visit();
	void student();
private:
	Student* s;
};
void VisitStudent::visit()
{
	cout << "年龄:" << s->m_Age << ",身高:" << s->m_Height << endl;
}
void VisitStudent::student()
{	
	s = new Student(175,21);
}
//全局友元函数
void func(Student& s)
{
	cout << "age:" << s.m_Age << endl;
}
//全局函数做友元的例子
void test01()//
{
	Student s1(170, 20);
	func(s1);
}
//类做友元的例子
void test02()//
{
	VisitStudent vs;
	vs.visit();
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

	//test01();////全局函数做友元的例子
	test02();////类做友元的例子
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif



#if 0
#include <iostream>
using namespace std;

class Teacher
{
public:
	Teacher() {}
	explicit Teacher(int age) :m_Age(age) {}

	int m_Age;
	string m_Name;
};
//不加explicit
void test01()
{
	//Teacher t1 = 13;//加了explicit报错

	//cout << t1.m_Age << endl;
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

	test01();////不加explicit
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
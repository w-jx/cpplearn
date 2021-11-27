#if 0
#include <iostream>
using namespace std;

class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << "我是Person类!里面有this指针" << endl;
		cout << mAge << endl;
	}

public:
	int mAge;
};
//空指针访问成员函数
void test01()//
{
	Person* p = nullptr;
	p->ShowClassName();//空指针可以调用成员函数
	p->ShowPerson();//成员函数中用到了this指针,就不可以了,不会报错,但是输出没有用
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

	test01();//空指针访问成员函数
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
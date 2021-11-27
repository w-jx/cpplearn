#if 0
#include <iostream>
using namespace std;

/*
函数调用运算符 ()  也可以重载,由于重载后使用的方式非常像函数的调用，因此称为仿函数

仿函数没有固定写法，非常灵活

*/
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
//仿函数例子1
void test01()//
{
	MyAdd add;
	cout << "1+2=" << add(1, 2) << endl;
}
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}

};
//仿函数例子2
void test02()//
{
	MyPrint myprint;
	myprint("helloworld");
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

	//test01();//仿函数例子
	test02();////仿函数例子2
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
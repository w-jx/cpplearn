#if 0
#include <iostream>
using namespace std;


int func1(int a, int b = 10)
{
	return a + b;
}
int func2(int a, int)
{
	cout << "a:" << a << endl;
	return 1;
}
//函数默认参数
void test01()//
{
	cout<<func1(1)<<endl;//11
	cout << func1(1, 2) << endl;//3
	//函数有多个参数,某个参数有默认值,从这个参数到最后一个参数都需要有默认值
	//函数声明有默认值,函数实现不能有默认值
}
//函数占位参数
void test02()//
{
	func2(1, 1);//占位参数必须填补
}

void funcsame()
{
	cout << "funcsame:" << endl;
}
void funcsame(int a)
{
	cout << "a:" << endl;
}
void funcsame(int a,int b)
{
	cout << "a,b" << endl;
}
void funcsame(int a, string s)
{
	cout << "a,s" << endl;
}

//函数重载
void test03()//
{
	//函数重载条件:1.同一个作用域,2.个数不同 3.顺序不同  函数的返回值不能作为函数重载的条件
	funcsame();
	funcsame(3);
	funcsame(1, 2);
	funcsame(1, "ss");
}
void func(int& a)
{
	cout << "func(int& a)" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)" << endl;
}
//函数重载注意事项  1引用做为重载条件
void test04()//
{
	int a = 10;
	func(10);//调用const 
	func(a);//调用无const
	const int b = 2;
	func(b);//调用const 
}
void func3(int a,int b=10) 
{	
	cout << "func3(int a,int b=10) " << endl;
}
void func3(int a)
{
	cout << "func3(int a) " << endl;
}
//函数重载碰到函数默认参数
void test05()//
{
	//func3(10);//这个引起歧义,报错
	func3(10, 10);//第一个
	//不管怎么弄都运行不到第二个要避免这种情况
}

void test06()//
{

}



int main(void)
{

	//test01();//函数默认参数
	//test02();//函数占位参数
	//test03();//函数重载
	//test04();//函数重载注意事项  1引用做为重载条件
	test05();//函数重载碰到函数默认参数
	//test06();//

	system("pause");
	return 0;

}
#endif
﻿#if 0
#include <iostream>
using namespace std;

template<class T1,class T2>
void func1( T1& p1, T2& p2)
{
	std::cout << p1 << "," << p2 << std::endl;
}


template<typename T>
 void func2(const T& a, const T& b)
{
	std::cout << a << "," << b << std::endl;
}
//----------------------------------------------------------------------------
void test01()//函数模板
{
	//推导1.自动类型推导 2.必须给出模板类型才能调用

	//func1(1, 'a');//如果函数变量参数没有const 限制,这边会报错
	int a = 1;
	char b = 'a';
	func1(a, b);

	//func2(3, 4);
}
////可变参数 模板
//template<typename... T>
//void func(T...args) {
//	cout << "arg nums:" << sizeof(args) << endl;
//}
int main(void)
{
	//test01();//函数模板


	system("pause");
	return 0;

}
#endif

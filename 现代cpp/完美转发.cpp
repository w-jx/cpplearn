#if 1
#include <iostream>
#include <vector>
using namespace std;

// 接收左值
void fun(int& lvalue)
{
	std::cout << "lvalue = " << lvalue << std::endl;
}
// 接收右值
void fun(int&& rvalue)
{
	std::cout << "rvalue = " << rvalue << std::endl;
}
//在没有完美转发时候,没有万能引用
void test01()
{
	int x = 10;
	fun(x);//左值
	fun(10);// 右值
	fun(std::move(x)); //std::move(x) == static_cast<int&&>(x) 将左值转发为右值
}
//下面是万能引用，同时支持左值参数和右值参数，不用重载------引用折叠 只有&& &&才是右值 
template<typename T>
void fun1(T&& param)
{
	std::cout << "lvalue or rvalue = " << param << std::endl;
}

void fun2(int const& val) //上面的万能引用 实际上可以用这个替代？，虽然能替代，但是出现的问题是，无法修改val 
{
	std::cout << "fun2,lvalue or rvalue = " << val << std::endl;
}
//万能引用测试
void test02()
{
	int x = 10;
	fun1(x);//左值
	fun1(10);//右值
	fun1(std::move(x));//右值


	fun2(x);
	fun2(10);
	fun2(std::move(x));
}
//下面是完美转发--错误  左值引用右值引用本身都是----左值
template<typename T>
void function(T&& param)
{
	fun(param);
}
//完美转发错误的结果测试
void test03()
{
	int x = 10;
	function(x);//左值
	function(std::move(x));//右值
	
}

//下面是完美转发--正确版本
template<typename T>
void function1(T&& param)
{
	//fun(param);
	fun(std::forward<T>(param)); // 使用std::forward进行完美转发
}
//完美转发正确版本测试
void test04()
{
	int x = 10;
	function1(x);//左值
	function1(std::move(x));//右值

}
int main(void)
{
	//test01();//没有完美转发的情况
	//test02();//万能引用的情况
	//test03();//完美转发的 错误结果，发现都是左值，因为左值右值引用 本身都是左值
	test04();//完美转发的 正确结果
	
	return 0;
}
#endif
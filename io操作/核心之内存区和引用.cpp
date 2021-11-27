#if 0
#include <iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;


//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

//内存分区模型
/*
编译程序生成了exe可执行程序,未执行程序前分为两个区域
1.代码区:存放cpu执行的机器指令,代码区是共享的,在内存中只有一份代码就行,代码区是只读的防止程序意外修改指令
2.全局区:全局变量和静态变量存放在这边,还包含了常量区,包括字符串常量和其他常量,全局区的数据在程序结束后由操作系统释放

程序运行后
栈区:由编译器自动分配释放,存放函数的参数值,局部变量等

堆区:由程序员分配释放,若程序员不是放,程序结束时由操作系统回收,主要用new在堆区开辟内存

*/
int& func1() //返回局部变量引用,错误用法示例
{
	int a = 10;//局部变量
	return a;
}

int& func2()
{	
	static int s_a = 7;
	return s_a;
}
//内存分区模型
void test01()//
{
	//局部变量
	int a = 10;
	int b = 10;

	//打印地址
	cout << "局部变量a地址为： " << (int)&a << endl;
	cout << "局部变量b地址为： " << (int)&b << endl;

	cout << "全局变量g_a地址为： " << (int)&g_a << endl;
	cout << "全局变量g_b地址为： " << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;

	cout << "静态变量s_a地址为： " << (int)&s_a << endl;
	cout << "静态变量s_b地址为： " << (int)&s_b << endl;

	cout << "字符串常量地址为： " << (int)&"hello world" << endl;
	cout << "字符串常量地址为： " << (int)&"hello world1" << endl;

	cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;
	cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;
	cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;
}
//引用基础
void test02()//
{
	//引用作用,给变量起别名
	int a = 10;
	int& b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	b = 100;//修改了b也就修改了a,因为b就是a的别名
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//引用注意事项:1.引用必须初始化,指明给谁起别名,2.引用初始化之后不得修改对象

	//引用可以做函数参数,通过引用传参和指针传参效果相同,语法更简单

	//引用 做函数返回值,引用可以作为函数的返回值存在,注意不要返回局部变量的引用,因为局部变量在栈区,函数执行结束编译器就回收了
	//用法:函数调用做为左值
	int& ref = func1();
	cout << "ref=" << ref << endl;//10
	cout << "ref=" << ref << endl;//ref = 2035992960乱了,第一次由编译器保留

	int &ref2 = func2();
	cout << "ref2=" << ref2<< endl;//7
	cout << "ref2=" << ref2<< endl;//7


	func2() = 1000;//函数作为左值,必须返回引用
	cout << "ref=" << ref2 << endl;//1000
	cout << "ref=" << ref2 << endl;//1000
	
}
//引用的本质,在c++内部是指针常量
void test03()//
{
	int a = 10;
	
	int* const ref = &a;
	*ref = 20;
	cout << "a =" << a << endl;
	cout << "ref = " << *ref << endl;

	int& ref2 = a;//自动转换为int *const ref2 = &a;
	ref2 = 30;//内部发现ref2是引用,自动转换为 *ref2 = 30
	cout << "a =" << a << endl;
	cout << "ref2 = " << ref2 << endl;

}
//常量引用
void test04()//
{
	const int& ref = 10;//常量引用
	//ref = 100;//不可修改
}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	//test01();//内存分区模型
//test02();//引用技术
	//test03();////引用的本质,在c++内部是指针常量

	test04();//常量引用
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif

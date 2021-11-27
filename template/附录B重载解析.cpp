#if 0
#include "wjxHeaders.h"
#include<stddef.h>

void combine(int a, double b)
{
	cout << "int,double\n";
}
void combine(long a, int b)
{
	cout << "long,int\n";
}

void test01()
{
	//combine(1, 2);//出现二义性
/*
对于函数1，参数1  1是int,最佳匹配
对于函数2，参数2  2是int，最佳匹配
尽管，int 和long的相似度 > int 和double 的相似度，但是c++不会去试图度量这种多个调用实参的相似度
因此会出现二义性
*/




/*//匹配分级  调用实参的类型  和 候选函数相应参数的 匹配程度
int f1(int) 函数1
int f1(double) 函数2
int f2(int) 函数3
int f2(char) 函数4

class X {
	public:
		X(int);

}

int f3(X) 函数5
int f3(...) 函数6

 1.完美匹配
	参数的类型和实参完全相同
	参数的类型是指向实参类型的引用，或者是增加const ,volatile限定
2.细微调整的匹配
	数组 转变成指向数组第一个元素的指针
	或者添加const ,从而让类型int ** 的实参匹配类型为int const * const *等
3.发生提升的匹配
提升是一种隐式类型转换
	1.把占位少的类型（bool,char,short,或者某些枚举)  转换为占位多的类型（int,unsigned int,long,unsigned long)
	还包括从float到double的类型转换
4.发生标准转型（类型转换）的匹配。
这包含任何种类的标准转型（诸如int到float），但并不包含隐式调用的类型转换运算符和单参数构造函数。
5.
发生用户自定义转型的匹配。这允许任何种类的隐式类型转换。

6.
和省略号的匹配。省略号参数可以匹配任何类型（但匹配非POD（plain old data）类型会导致未经定义的行为）。


f1(4)  --->函数1精确匹配，函数2需要标准转型
f2(true)--->调用函数3，发生提升的匹配，函数4要求标准转型
	
f3(7) --->调用函数5，发生自定义转型的匹配，而函数6要求和省略号匹配？？？


重载解析 是在  模板参数演绎  之后，演绎不会考虑上面的这些类型转换，下面是例子

template <typename T>
class MyString {

public:

MyString(T const*);　　　//能够进行类型转换的构造函数
...

};
template <typename T>
MyString<T> truncate(MyString<T> const&, int);

int main()
{

MyString<char> str1, str2;

str1 = truncate<char>(”Hello World”, 5);　//正确

str2 = truncate(”Hello World”,5);　　　　 //错误

}

在模板实参的演绎过程中，并不会考虑这种由单参数构造函数所提供的隐式转型。
在给str2赋值的过程中，并不能找到任何可行的truncate()函数；因此根本就不会执行重载解析。

自己的理解：构造函数是重载函数，模板演绎在前，那时候不会考虑重载，不会考虑这种隐式转换？？？
*/
}


template <typename T>
class MyString {

public:
	MyString(){}
	MyString(T const*str) {//能够进行类型转换的构造函数
		cout << "有参构造调用\n";
	}
};
template <typename T>
MyString<T> truncate(MyString<T> const&str, int a)
{
	cout << "a=" << a << endl;

	return str;
}
//test01()是大部分的原则，还有一些不能解释的，在test02()记录
void test02()
{
	/*
	对于一个 非静态 成员函数，包括了一个隐含的参数 *this
	对于类Myclass 隐含的参数一般是Myclass & (non-const 成员函数）
	或者是Myclass const & (针对const 成员函数）

	*this 可能会出现意外的结果,下面的例子没有看懂
	*/

}
//class BadString {
//
//public:
//
//	BadString(char const*);//有参构造
//
//	//通过下标运算符来访问字符
//
//	char& operator[] (size_t);//函数1
//
//	char const& operator[] (size_t) const;
//
//	//隐式转型为以null结束的字符串
//
//	operator char* ();//函数2
//
//	operator char const* ();
//	
//下面利用这个类写一点东西
/*
int main()
{
	BadString str("correkt"); //构造对象，调用有参构造

	str[5]='s';//可能会出现二义性
}
实参5的类型是int  
运算符所期望的类型是无符号的整数类型
size_t  std::size_t 代表unsigned int 和unsigned long类型，肯定不是int 型
要匹配函数1 ，需要进行一次标准整形转换
还有另外一个隐含的候选函数，内建（即相对于char *) 的下标运算符
	如果我们对str 应用隐式类型转换（因为str 是一个类似于this 的隐式成员函数实参） ，我们就可以可获得一个指针类型char *
	之后就可以使用内建的下标运算符了，内建的下标运算符接受ptrdiff_t 类型的实参，在某些平台ptrdiff_t 等同int,所以
	该类型是5的完美匹配

因此，就隐式实参（str,也就是*this),内建的下标运算符可能是不太好的匹配（会先进行用户自定义的类型转换），但它比
函数1定义的下标运算符的匹配更好，从而出现潜在的二义性

为了 可移植地解决问题
	1.可以声明运算符接受的是ptrdiff_t 类型
	或者
	2.可以把char * 的隐式类型转换 改成 显示类型转换 （推荐）

*/
//细化完美匹配
void test03()
{
	//int 类型，int,int & int const & 都可以获得完美匹配
	/*
	void report(int &);//函数1
	void report(int const &);//函数2

	int k=1;
	report(k);调用函数1
	report(42);调用函数2  
	//结论1：实参左值，优先考虑无const 版本
	//结论2:实参右值，优先考虑有const版本
	void report(int) ;//函数1
	void report(int &);//函数2
	void report(int const &);//函数3

	int k=0;
	report(k); //出现二义性，函数1和函数2 匹配程度相同
	report(42);//出现二义性，函数1和函数3 匹配程度相同

	总而言之：

•对于T类型的右值，T和T const&的匹配程度一样。

•对于T类型的左值，T和T&的匹配程度一样


B31 非模板优先
template <typename T> int f(T);　　　 //(1)
void f(int);　　　　　　　　　　　　　 //(2)

return f(7)   //错误，选择了2，但是函数2并没有返回值
一句话说，函数返回值不能用来区分函数重载
	*/
}
template<typename T> int f(T a)
{

	cout << "T a\n";
	return 0;
}
void f(int a)
{
	cout << "a\n";
}
int main()
{
	MyString<char> str1, str2;
	MyString<char> str3("okwenjx");
	str1 = truncate<char>("hello,world", 5);//通过,显示指定函数模板实参，就可以进行重载解析了
	//str2 = truncate("hello,world", 5);//没有与参数列表匹配的函数模板truncate实例
	str3 = truncate(str3, 5);//通过



	f(2);//选择第二个
	//cout << f(3) << endl;//x选择的第二个，没有返回值
	system("pause");
	return 0;
}


#endif
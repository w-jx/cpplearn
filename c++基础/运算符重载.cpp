#if 0
#include <iostream>
using namespace std;

/*
加法运算符重载
<<运算符重载
关系运算符重载 比较简单例子就不写了
*/
class Person {
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person& p){
	//}
	//ostream& operator<<(ostream& out, Person& p);成员函数无法实现


private:
	int m_A;
	int m_B;
};
//左移运算符重载--Person类
void test01()//
{
	Person p1(10, 20);
	cout << p1 << ",hello,world" << endl;//链式编程
}
//++运算符重载,分为前置++ 和 后置++
class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger);
public:
	MyInteger() { this->m_Num = 0; };
	MyInteger(int a):m_Num(a){}

	//前置++
	MyInteger& operator++()
	{
		m_Num++;
		return *this;//返回对象本身
	}
	//后置++
	MyInteger operator++(int)
	{
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++
		m_Num++;
		return temp;
	}




private:
	int m_Num;
};

///++运算符重载,分为前置++ 和 后置++
void test02()//
{
	MyInteger myint;//默认里面的m_Num=0
	cout << myint << endl;//0
	cout << myint++ << endl;//0
	cout << ++myint << endl;//2

	MyInteger myint2;//默认里面的m_Num=0
	cout << myint2 << endl;//0
	cout << ++myint2 << endl;//0
	cout << myint2++ << endl;//2
	
}
/*
赋值运算符重载
编译器给一个类添加除了三个构造函数,还有赋值运算符=,对属性进行值的拷贝
如果属性中有属性在堆区,做赋值操作会出现深拷贝和浅拷贝问题
*/
class Person1
{
public:

	Person1(int age)
	{
		//将年龄数据开辟到堆区
		m_Age = new int(age);
	}

	//重载赋值运算符 
	Person1& operator=(Person1& p)
	{
		if (m_Age != NULL)
		{
			cout << "this->m_Age:" << *this->m_Age<<endl;
			delete m_Age;
			m_Age = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);
		cout << "this->m_Age:" << *this->m_Age << endl;
		//返回自身
		return *this;
	}

	~Person1()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	//年龄的指针
	int* m_Age;

};
//=运算符重载例子,如果注释了重载=号程序
void test03()//
{
	Person1 p1(18);
	Person1 p2(20);
	Person1 p3(30);
	//cout << "p1的年龄为：" << *p1.m_Age << endl;
	//cout << "p2的年龄为：" << *p2.m_Age << endl;
	//cout << "p3的年龄为：" << *p3.m_Age << endl;
	p3 = p2 = p1;
	//cout << "p1的年龄为：" << *p1.m_Age << endl;
	//cout << "p2的年龄为：" << *p2.m_Age << endl;
	//cout << "p3的年龄为：" << *p3.m_Age << endl;

	//不注释 = 运算符重载程序,程序是正常的,注释了以后cpplearn.exe 已触发了一个断点。

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




ostream& operator<<(ostream& out, Person& p)
{
	out << "a:" << p.m_A << ",b:" << p.m_B;
	// TODO: 在此处插入 return 语句
	return out;
}

ostream& operator<<(ostream& out, MyInteger myinteger)
{
	out << myinteger.m_Num;
	return out;// TODO: 在此处插入 return 语句
}



int main(void)
{

	//test01();//左移运算符重载
	//test02();//++运算符重载
	test03();//=运算符重载例子
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif


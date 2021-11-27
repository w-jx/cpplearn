#if 0
#include <iostream>
using namespace std;
/*
C++中拷贝构造函数调用时机通常有三种情况
* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象

*/
class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
		mAge = 0;
	}
	Person(int age) {
		cout << "有参构造函数!" << endl;
		mAge = age;
	}
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		mAge = p.mAge;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int mAge;
};
//1.使用一个已经创建完毕的对象来初始化新对象,正常拷贝构造
void test01()//
{
	Person man(100);//对象已经创建完毕了

	Person newman(man);//调用拷贝构造函数

	Person newman2 = man;//拷贝构造
	
}
void doWork(Person p)
{

}
void doWork1(Person& p)
{
	p.mAge = 10;
}
//2.值传递的方式给函数参数传值
void test02()//
{
	Person p;
	doWork(p);//相当于Person p1 = p,所有调用拷贝构造函数
	doWork1(p);//没有新对象的参数
}
Person doWork2()
{
	Person p1;//无参构造调用
	cout << (int*)&p1 << endl;
	return p1;//拷贝构造调用

}
//3.以值方式 返回局部对象
void test03()//
{
	Person p = doWork2();
	cout << (int*)&p << endl;
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

	//test01();//1.使用一个已经创建完毕的对象来初始化新对象,正常拷贝构造
	//test02();//2.值传递的方式给函数参数传值
	test03();//3.以值方式 返回局部对象
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
#if 0
#include "wjxHeaders.h"

//递增运算符重载	++

//自定义整形
class MyInteger
{
	friend	ostream& operator<<(ostream& cout, MyInteger myint);
	//重载<<运算符
public:
	MyInteger()
	{
		M_num = 0;
	}
	MyInteger(int i):M_num(i){}
	//重载++运算符，前置
	MyInteger& operator++()//如果返回的不是引用，那么返回的就是一个新的对象，相当于拷贝
	{						//返回确保一直是对一个对象操作
		M_num++;
		return *this;//将自身返回
	}
	//重载++运算符，后置
	MyInteger operator++(int)//int代表占位参数，可以用于区分前置和后置递增
	{							//后置递增一定返回的值，不是引用，如果返回引用，这是个局部对象，用完会被释放
								//再返回就是非法操作
		//先记录一下当时的结果
		MyInteger	temp = *this;
		//后递增
		M_num++;
		//最后讲记录的结果返回
		return temp;
	}
private:
	int M_num;
};
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.M_num;
	return cout;
}
void test01()//前置++
{
	MyInteger myint=4;
	cout << ++myint << endl;
}
void test02()//后置++
{
	MyInteger myint=10;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	//test01();//前置++
	test02();//后置++
	system("pause");
	return 0;
}
#endif
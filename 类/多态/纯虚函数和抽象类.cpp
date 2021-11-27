#if 1
#include <iostream>
using namespace std;
/*
多态中,父类中虚函数的实现意义不大,主要调用的都是子类重写虚函数的内容,因此可以
将父类中的虚函数改成纯虚函数
virtual returnValueType funcName(paramList) = 0;
当类中有纯虚函数,这个类称为	抽象类
1.无法实例化对象
2.子类必须重写抽象类中的纯虚函数,否则也属于抽象类,无法实例化对象
*/
class Base
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;

};
class Son :public Base
{
public:
	virtual void func() //子类中重写的纯虚函数可以加virtual关键字也可以不加关键字
	{
		cout << "func调用" << endl;
	};
};
//测试
void test01()//
{
	Base* base = NULL;
	//base = new Base;//抽象类无法实例化对象
	base = new Son;
	base->func();

	delete base;//记得销毁
}

int main(void)
{

	test01();////测试

	system("pause");
	return 0;

}
#endif
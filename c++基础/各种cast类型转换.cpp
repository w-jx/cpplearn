#if 0
#include "wjxHeaders.h"

class Base {
public:
	Base() = default;
	//virtual ~Base(){}
	virtual void testBase() {
		cout << "hello,base\n";
	}
};
class Child :public Base
{
public:
	Child() = default;
	//virtual ~Child(){}
	virtual void testBase() {
		cout << "hello,child\n";
	}

};
void test01()
{
	Base* base = new Child();//基类指针 指向子类对象，多态
	base->testBase();//多态，输出child
	delete base;

	base = new Base();//基类
	base->testBase();//hello,base;
	Child* child = new Child;//子类

	//static_cast 可以安全的向上转换  子类->基类
	(static_cast<Base*>(child))->testBase(); //hello,child
	//static_cast 不能安全的向下转换
	(static_cast<Child*>(base))->testBase();//hello base   


	child->testBase();//hello,child
	base->testBase();//hello base

	//(dynamic_cast<Base*>(child))->testBase();//向上转换可以，但没必要，因为有额外开销
	//向下转换 有类型检查，非法的指针返回nullptr,引用有bad_cast异常  我这边的转换是异常的
	if (auto childtemp = dynamic_cast<Child*>(base))
		childtemp->testBase();
	else {
		cout << "dynamic_cast base to Child* error\n";
	}
		

	delete base;
	delete child;
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
/*
多态使用时,如果子类中有属性开辟到堆区,父类指针释放时无法调用到子类的析构代码
解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性:
可以解决父类指针释放子类对象
都需要有具体的函数实现
区别:
如果是纯虚析构，该类属于抽象类，无法实例化对象
*/
class Animal {
public:

	Animal()
	{
		cout << "Animal 构造函数调用！" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;
	//}
	~Animal();

	//virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal 析构函数调用！" << endl;
	//cout << "Animal 纯虚析构函数调用！" << endl;
}
class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name << "小猫在说话!" << endl;
	}
	~Cat()
	{
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string* m_Name;
};
//父类不添加虚析构时的情况
void test01()//
{
	Animal* animal = new Cat("tom");
	animal->Speak();
	delete animal;
	//发现没有执行Cat析构函数的调用,这样很可能会造成内存泄漏
}
//父类添加虚析构
void test02()//
{
	Animal* animal = new Cat("Jerry");
	animal->Speak();
	delete animal;
}
//父类添加纯虚析构,并且不实现析构函数的情况,无法解析的外部命令,必须要实现纯虚析构函数
void test03()//
{

	Animal* animal = new Cat("haha");
	animal->Speak();
	delete animal;
}


int main(void)
{

	test01();////不添加虚析构时的情况
	//test02();////父类添加虚析构
	//test03();//父类添加纯虚析构,并且不实现析构函数的情况


	system("pause");
	return 0;

}
#endif
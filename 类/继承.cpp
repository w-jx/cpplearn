#if 0
#include <iostream>
using namespace std;

/*
继承的好处:减少重复的代码
class A:public/private/protected B
派生类的成员:1.基类继承过来的,表现其共性   2.自己增加的成员,体现其个性

继承方式:
公共继承:父类的公共成员在子类仍然是公共的,父类的保护成员在子类仍然是保护的,父类的私有成员子类无法访问
保护继承:父类的公共成员和保护成员 在子类都是保护成员 ,父类的私有成员子类无法访问
私有继承:父类的公共成员和保护成员 在子类的都是私有成员.父类的私有成员子类无法访问

父类中的对象模型,见实例1
*/
//实例1
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};
//公共继承
class Son :public Base
{
public:
	int m_D;
};
//实例1
void test01()//
{
	/*
	Base中分别一个公共,一个保护,一个私有,然后Son自己有一个公共的成员,大小是16
	虽然Son无法访问父类的私有变量,说明也是继承下来
	*/
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

void test02()//
{

}

void test03()//
{

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

	test01();////实例1
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
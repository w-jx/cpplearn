#if 0
#include <iostream>
using namespace std;
/*
* 
多继承因为实际开发中不推荐使用,就不说了,加作用域区分即可

**菱形继承概念：**
两个派生类继承同一个基类,又有某个类同时继承者两个派生类
			动物
	羊(动物)  骆驼(动物)
		羊驼(羊,骆驼)
1.羊和骆驼都继承了动物类,当羊驼使用属性,会产生二义性
2/羊继承自动物的数据继承了两份,应该只需要继承一份就行了
利用virtual关键字虚继承  继承前加virtual关键字后，变为虚继承
此时公共的父类Animal称为虚基类
*/
class Animal
{
public:
	int m_Age;
};
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};
//菱形继承 虚继承测试
void test01()//
{
	SheepTuo st;
	st.Sheep::m_Age = 100;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;//3个打印全是100
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;

	st.Tuo::m_Age = 200;
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;//3个打印全是200
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;

	//这样继承的数据就只有一份了,不会造成资源的浪费
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

	test01();//菱形继承 虚继承测试
	//test02();//
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
#if 1
#include <iostream>
using namespace std;
/*
多态分类:
静态多态: 函数重载   运算符重载 属于静态多态,复用了函数名
动态多态:派生类  和 虚函数  实现运行时多态

静态多态和动态多态区别:
静态多态的函数地址早绑定,--编译阶段确定函数地址
动态多态的函数地址晚绑定,--运行阶段确定函数地址

*/
class Animal
{
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};
//上面有三个类,每个里面都有说话函数,分别是动物.小猫,小狗说话,我们希望传入对象,就调用什么对象的函数
//例如传入小猫,就来小猫在说话
//只有Animal类
void test01()//
{
	Animal a;
	a.speak();
}
//如果函数地址在编译阶段就能确定,那么是静态联编
//如果函数地址在运行阶段才能确定,就是动态联编
void DoSpeak(Animal& animal)
{
	animal.speak();
}
/*
多态条件:
1.有继承关系
2.子类重写父类中的虚函数
多态的使用:
父类指针  或引用    指向子类对象
*/
//多态使用案例
void test02()//
{
	Cat cat;  //Animal& animal = cat
	DoSpeak(cat);

	Cat c1;
	Animal& a = c1;//父类引用指向子类对象
	DoSpeak(c1);

	Animal* b = new Cat();//父类指针指向子类对象
	DoSpeak(*b);



	Dog dog;
	DoSpeak(dog);
}




int main(void)
{

	//test01();////只有Animal类
	test02();////多态使用案例


	system("pause");
	return 0;

}
#endif
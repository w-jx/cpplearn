#if 1
#include <iostream>
using namespace std;
/*
浅拷贝:简单的赋值拷贝操作
深拷贝:在堆区重新申请空间,进行拷贝操作
*/
class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age, int height) {

		cout << "有参构造函数!" << endl;

		m_age = age;
		m_height = new int(height);

	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		m_height = new int(*p.m_height);

	}

	//Person(Person &&p):m_age(std::move(p.m_age)),m_height(std::move(p.m_height))
	//{
	//	cout << "移动构造\n";
	//	

	//}

	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
		if (m_height != nullptr)
		{
			delete m_height;
			m_height = nullptr;
		}
		
	}

	int m_age;
	int* m_height;
};
//注释拷贝构造,观察浅拷贝的问题
void test01()//
{
	Person p1(19, 189);
	Person p2(p1);
	cout << "p1的年龄： " << p1.m_age << " 身高： " << (int *)p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << (int *)p2.m_height << endl;
	/*
	这边报错,cpplearn.exe 已触发了一个断点,因为这边有p1,p2两个对象
	所以析构函数执行两次,然后这边

	delete m_height;执行了两遍,两个指向的是同一块内存区域,所以释放两次报错
	(int *)p1.m_height :00ED5C38
	(int *)p2.m_height :00ED5C38

	所以需要自己写拷贝构造函数在拷贝时在堆区重新申请内存

	*/
	//cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	//cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;

}
class Student
{
	//Student(int age, int height)//传统方式初始化
	//{
	//	this->m_Age = age;
	//	this->m_Height = height;
	//}
	Student(int a,int b):m_Age(a),m_Height(b) {}//这样更简单

public:
	int m_Age;
	int m_Height;
};
//初始化列表初始化
void test02()//
{

}



int main(void)
{

	test01();//注释拷贝构造,观察浅拷贝的问题
	//test02();//


	
	return 0;

}
#endif
#if 0
#include <iostream>
using namespace std;

template<class T1,class T2>
void func1( T1& p1, T2& p2)
{
	std::cout << p1 << "," << p2 << std::endl;
}


template<typename T>
 void func2(const T& a, const T& b)
{
	std::cout << a << "," << b << std::endl;
}


//----------------------------------------------------------------------------

void test01()//����ģ��
{
	//�Ƶ�1.�Զ������Ƶ� 2.�������ģ�����Ͳ��ܵ���

	//func1(1, 'a');//���������������û��const ����,��߻ᱨ��
	int a = 1;
	char b = 'a';
	func1(a, b);

	//func2(3, 4);



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

	test01();//����ģ��
	//test02();//
	//test03();//
    //test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif

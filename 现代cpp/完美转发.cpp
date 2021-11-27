#if 1
#include <iostream>
#include <vector>
using namespace std;

// ������ֵ
void fun(int& lvalue)
{
	std::cout << "lvalue = " << lvalue << std::endl;
}
// ������ֵ
void fun(int&& rvalue)
{
	std::cout << "rvalue = " << rvalue << std::endl;
}
//��û������ת��ʱ��,û����������
void test01()
{
	int x = 10;
	fun(x);//��ֵ
	fun(10);// ��ֵ
	fun(std::move(x)); //std::move(x) == static_cast<int&&>(x) ����ֵת��Ϊ��ֵ
}
//�������������ã�ͬʱ֧����ֵ��������ֵ��������������------�����۵� ֻ��&& &&������ֵ 
template<typename T>
void fun1(T&& param)
{
	std::cout << "lvalue or rvalue = " << param << std::endl;
}

void fun2(int const& val) //������������� ʵ���Ͽ�����������������Ȼ����������ǳ��ֵ������ǣ��޷��޸�val 
{
	std::cout << "fun2,lvalue or rvalue = " << val << std::endl;
}
//�������ò���
void test02()
{
	int x = 10;
	fun1(x);//��ֵ
	fun1(10);//��ֵ
	fun1(std::move(x));//��ֵ


	fun2(x);
	fun2(10);
	fun2(std::move(x));
}
//����������ת��--����  ��ֵ������ֵ���ñ�����----��ֵ
template<typename T>
void function(T&& param)
{
	fun(param);
}
//����ת������Ľ������
void test03()
{
	int x = 10;
	function(x);//��ֵ
	function(std::move(x));//��ֵ
	
}

//����������ת��--��ȷ�汾
template<typename T>
void function1(T&& param)
{
	//fun(param);
	fun(std::forward<T>(param)); // ʹ��std::forward��������ת��
}
//����ת����ȷ�汾����
void test04()
{
	int x = 10;
	function1(x);//��ֵ
	function1(std::move(x));//��ֵ

}
int main(void)
{
	//test01();//û������ת�������
	//test02();//�������õ����
	//test03();//����ת���� �����������ֶ�����ֵ����Ϊ��ֵ��ֵ���� ��������ֵ
	test04();//����ת���� ��ȷ���
	
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;
/*

��������֪���÷������е�����
1.����ȫ�ֺ���ǰ����ʾ��ȫ��
	����˵��һ��std::max�����������Լ�������һ��max������������ͬ
	��::max����ʹ�õ���ȫ�ֵģ������Ǳ�׼ģ����
2.��ʾ���ó�Ա�������߱������������Ա��������൱��.
*/
class A
{
public:
	A() {};
	A(int _p1, int _p2, string _p3);
	int p1;
	int p2;
	string p3;
};
A::A(int _p1, int _p2, string _p3)//�������������ⶨ��
{
	this->p1 = _p1;
	this->p2 = _p2;
	this->p3 = _p3;
}
void test01()
{
	cout << "i am wenjx\n";
}
int main(void)
{
	::test01();//ð�ŷ���ȫ�ֺ���ǰ��ʾ��ȫ�ֺ���
	A a(1,2,"aaa");//�½���Աa
	cout << "a.p1=" << a.p1 << endl;//��ͳд��
	::A* newobj = new A;
	newobj->p1 = 1;
	newobj->p2 = 2;
	newobj->p3 = "wenlaoshi";

	cout << newobj->p3 << endl;
	//cout << "a.p1=" << a::p1 << endl;//�����
	//cout << "a.p1=" << A::p1 << endl;//�Ǿ�̬��Ա���ñ���Ҫ���ض���Ա��ԣ�����
	system("pause");
	return 0;
}
#endif
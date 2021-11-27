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
	Base* base = new Child();//����ָ�� ָ��������󣬶�̬
	base->testBase();//��̬�����child
	delete base;

	base = new Base();//����
	base->testBase();//hello,base;
	Child* child = new Child;//����

	//static_cast ���԰�ȫ������ת��  ����->����
	(static_cast<Base*>(child))->testBase(); //hello,child
	//static_cast ���ܰ�ȫ������ת��
	(static_cast<Child*>(base))->testBase();//hello base   


	child->testBase();//hello,child
	base->testBase();//hello base

	//(dynamic_cast<Base*>(child))->testBase();//����ת�����ԣ���û��Ҫ����Ϊ�ж��⿪��
	//����ת�� �����ͼ�飬�Ƿ���ָ�뷵��nullptr,������bad_cast�쳣  ����ߵ�ת�����쳣��
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
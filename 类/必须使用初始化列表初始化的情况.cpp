#if 0
#include "wjxHeaders.h"

class Base {
public:
	Base(int _num) {
		this->num = _num;
	}
	int getNum()const {
		return this->num;
	}
private:
	int num;
};
//����ʹ�ó�ʼ���б��ʼ�������1
/*
1.�б������Ϊ�����Ǹ��໹û��Ĭ�Ϲ��캯��
*/
class Test1 {
public:
	Test1():base(1) {
		cout << this->base.getNum() << endl;
	}
private:
	Base base;
};
//���2�����const �����������͵ĳ�Ա����
class Test2 {
public:
	Test2():c(10),refnum(c),constval(2) {

	}
private:
	int& refnum;
	const int constval;
	int c;
};
//���3,����û��Ĭ�Ϲ��캯��ʱ
class Test3 :public Base {
public:
	Test3():Base(2){

	}
};
void test01()
{
	Test1 test1;
	Test2 test2;
	Test3 test3;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
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
//必须使用初始化列表初始化的情况1
/*
1.有别的类作为对象，那个类还没有默认构造函数
*/
class Test1 {
public:
	Test1():base(1) {
		cout << this->base.getNum() << endl;
	}
private:
	Base base;
};
//情况2，针对const 或者引用类型的成员变量
class Test2 {
public:
	Test2():c(10),refnum(c),constval(2) {

	}
private:
	int& refnum;
	const int constval;
	int c;
};
//情况3,父类没有默认构造函数时
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
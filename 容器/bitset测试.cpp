#if 0
#include "wjxHeaders.h"

//bitset �������������Ҫ�ڱ�����ȷ����С�����ܶ�̬����

void test01()
{
	bitset<5> mybit;
	mybit[0] = 1;
	mybit[1] = 1;
	mybit[2] = 1;
	mybit[3] = 0;
	mybit[4] = 1;

	cout << mybit.to_string() << endl;
	cout << mybit.to_ulong() << endl;



}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
#if 0
#include "wjxHeaders.h"

//��������Ϥ��λ���㣻

void test01()
{
	int ret=0x6;
	int b = 1;
	while ((b & ret) == 0)
		b <<= 1;    //��������ҵ�ret�ж����ƴӵ�λ��ʼ��һ��Ϊ1����
	cout << "ret=" << ret << endl;
	cout << "b=" << b << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
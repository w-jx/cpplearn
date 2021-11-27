#if 0
#include "wjxHeaders.h"

//首先先熟悉下位运算；

void test01()
{
	int ret=0x6;
	int b = 1;
	while ((b & ret) == 0)
		b <<= 1;    //这个可以找到ret中二进制从地位开始第一个为1的数
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
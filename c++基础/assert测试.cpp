#if 1
#include "../wjxHeaders.h"
#include <cassert>

void test01()
{
	//assert(5 > 0);//������ʽΪ�棬ûë��

	assert(5 < 0);//������ʽΪ�٣�abort() is called
}
int main()
{
	test01();
}
#endif
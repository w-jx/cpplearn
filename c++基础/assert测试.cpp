#if 1
#include "../wjxHeaders.h"
#include <cassert>

void test01()
{
	//assert(5 > 0);//如果表达式为真，没毛病

	assert(5 < 0);//如果表达式为假，abort() is called
}
int main()
{
	test01();
}
#endif
#if 0
#include "wjxHeaders.h"


using mytask = struct {
	int a;
	int b;
	
};
void test01()
{
	queue<mytask> taskque;
	mytask task1;
	task1.a = 2;
	task1.b = 3;

	mytask task2;
	task2.a = 2;
	task2.b = 3;

	taskque.push(task1);
	taskque.push(task2);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
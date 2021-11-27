#if 0
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
void test01()
{
	char recv_buf[512] = { 0 };

	for (auto i = 0; i < 10; i++) {
		recv_buf[i] = 'a' + i;
	}
	cout << recv_buf << endl;


	if (strcmp("abcdefghij", recv_buf))
		cout << "hhhhh\n";
	else
		cout << "1111\n";
}
void test02()
{
	std::cout << sizeof('a') << std::endl;
}
int main(void)
{

	//test01();
	test02();
	/*system("pause");*/
	while (1);
	return 0;
}
#endif


#if 0
#include "wjxHeaders.h"

struct Book {

	char name[1024];
	int page_nums;
	char country[1024];
};

struct Room {
	char owner[1024];
	double square;
}room1 = { "wenjx",200 };//������ֱ�ӳ�ʼ��

void test01()
{
	Book book; //c���У�����struct Book book


	Book book1{ "wenjx",100,"hello" };//c���У�����Ҫ��=

	cout << "owner=" << room1.owner << ",square=" << room1.square << endl;




}
int main()
{

	test01();
	system("pause");
	return 0;
}


#endif
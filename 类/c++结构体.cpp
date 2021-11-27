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
}room1 = { "wenjx",200 };//甚至能直接初始化

void test01()
{
	Book book; //c不行，必须struct Book book


	Book book1{ "wenjx",100,"hello" };//c不行，必须要加=

	cout << "owner=" << room1.owner << ",square=" << room1.square << endl;




}
int main()
{

	test01();
	system("pause");
	return 0;
}


#endif
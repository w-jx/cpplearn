#if 0
#include <stdio.h>
#include <stdlib.h>

struct Book{

	char * name;
	int page_nums;
	char* country;
};


struct Room {
	char* owner;
	double square;
}room1 = { "wenjx",200 };//甚至能直接初始化

void test01()
{
	 //Book book;//不行.真正的类型是struct book
	struct Book book = { "heel", 100, "China" };
	
	printf("owner=%s,square=%f", room1.owner, room1.square);

}
int main()
{

	test01();

	return 0;
}
#endif
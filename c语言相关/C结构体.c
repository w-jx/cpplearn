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
}room1 = { "wenjx",200 };//������ֱ�ӳ�ʼ��

void test01()
{
	 //Book book;//����.������������struct book
	struct Book book = { "heel", 100, "China" };
	
	printf("owner=%s,square=%f", room1.owner, room1.square);

}
int main()
{

	test01();

	return 0;
}
#endif
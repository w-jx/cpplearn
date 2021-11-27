#if 0
#include "wjxHeaders.h"
#include <set>

void test01()
{
	set<int> myset;
	int num = 0;
	for (int i = 0; i < 10; i++) {
		num = rand() % 100;
		cout << num << " ";
		myset.insert(num);
	}
	cout << "--------\n";
		
	for (auto iter : myset)
		cout << iter << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
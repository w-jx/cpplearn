#if 0
#include "wjxHeaders.h"

//通过rbegin访问最后一个元素
void test01()
{
	set<int> myset;
	for (int i = 0; i < 5; ++i)
		myset.insert(i);

	cout << *myset.cbegin() << endl;
	cout << *myset.crbegin() << endl;//
	cout << *myset.rbegin() << endl;//


	map<int,int> mymap;
	for (int i = 0; i < 5; ++i)
		mymap.insert({ i,i + 1 });
	cout << (*mymap.cbegin()).second << endl;//注意一定要加括号
	cout << (*mymap.crbegin()).second << endl;//注意一定要加括号
}	
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
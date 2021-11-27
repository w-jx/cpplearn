#if 0
#include "wjxHeaders.h"
/*
leecode题目介绍:


*/
void test01()
{
#if 0 //vector deque erase会返回下一个有效的迭代器 所以不能采用erase(iter++),会导致后面所有的迭代器失效
	vector<int> v{ 1,2,3,4,5,6 };
	auto iter = v.begin();
	auto temp = v.erase(iter);

	//cout << *iter << endl;迭代器失效
	cout << *temp << endl;//返回下一个有效的迭代器
#endif

#if 0 //map set multiset,multimap 可以采用erase(iter++)的方式
	map<int, int> mymap;
	for (int i = 1; i < 10; ++i)
		mymap[i] = i;
	auto mapiter = mymap.begin();
	auto nextiter = mapiter++;//不支持+1操作，但是支持++操作
	auto itertemp  = mymap.erase(mapiter);

	//cout << (*mapiter).second << endl; //删除导致迭代器失效
	cout << (*itertemp).second << endl;//返回下一个有效的迭代器
	cout << (*nextiter).second << endl;//返回下一个有效的迭代器

	//list 都可以
#endif 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
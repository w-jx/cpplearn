#if 0
#include "wjxHeaders.h"

//ͨ��rbegin�������һ��Ԫ��
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
	cout << (*mymap.cbegin()).second << endl;//ע��һ��Ҫ������
	cout << (*mymap.crbegin()).second << endl;//ע��һ��Ҫ������
}	
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
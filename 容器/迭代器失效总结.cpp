#if 0
#include "wjxHeaders.h"
/*
leecode��Ŀ����:


*/
void test01()
{
#if 0 //vector deque erase�᷵����һ����Ч�ĵ����� ���Բ��ܲ���erase(iter++),�ᵼ�º������еĵ�����ʧЧ
	vector<int> v{ 1,2,3,4,5,6 };
	auto iter = v.begin();
	auto temp = v.erase(iter);

	//cout << *iter << endl;������ʧЧ
	cout << *temp << endl;//������һ����Ч�ĵ�����
#endif

#if 0 //map set multiset,multimap ���Բ���erase(iter++)�ķ�ʽ
	map<int, int> mymap;
	for (int i = 1; i < 10; ++i)
		mymap[i] = i;
	auto mapiter = mymap.begin();
	auto nextiter = mapiter++;//��֧��+1����������֧��++����
	auto itertemp  = mymap.erase(mapiter);

	//cout << (*mapiter).second << endl; //ɾ�����µ�����ʧЧ
	cout << (*itertemp).second << endl;//������һ����Ч�ĵ�����
	cout << (*nextiter).second << endl;//������һ����Ч�ĵ�����

	//list ������
#endif 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
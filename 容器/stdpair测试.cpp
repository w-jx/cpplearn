#if 0
#include "wjxHeaders.h"
/*
leecode题目介绍:


*/
void test01()
{
	std::pair left(0, 0);

	cout << left.first << "," << left.second << endl;


	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<vector<int> > vret;
	vret.push_back(v);

	//cout << vret[left] << endl;//不能这样操作
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
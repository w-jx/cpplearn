#if 0
#include "wjxHeaders.h"

void test01()
{
	vector<int> vret{ 1,6,2,3,4,5 };
	make_heap(vret.begin(), vret.end());
	cout << vret.front() << "," << vret.back() << endl;//6,2

	vector<int> v{ 2,4,3,8,5,10 };
	make_heap(v.begin(), v.end(),std::greater<int>());
	cout << v.front() << "," << v.back() << endl;//2,10

	vector<int> v1{62,7,10,23,17};
	make_heap(v1.begin(), v1.end(), std::less<int>());//默认大根堆
	cout << v1.front() << "," << v1.back() << endl;//62,17

	pop_heap(v1.begin(), v1.end());
	cout << v1.front() << "," << v1.back() << endl;//62,17
	for_each(v1.begin(), v1.end(), [=](int x) {cout << x << " "; });
	
	cout << endl;

	pop_heap(v1.begin(), v1.end()-1);
	cout << v1.front() << "," << v1.back() << endl;//62,17
	for_each(v1.begin(), v1.end(), [=](int x) {cout << x << " "; });//末尾是保持不变的


}

int main()
{
	test01();

	system("pause");
	return 0;
}
#endif
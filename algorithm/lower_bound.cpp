#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void test01()//
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++) {
		int num = rand() % (10) + 2;
		v1.push_back(num);
		if (v2.empty())
			v2.push_back(num);
		else
			v2.insert(std::lower_bound(v2.begin(), v2.end(), num), num);

	}
	for_each(v1.begin(), v1.end(), [=](int x) {std::cout << x << " "; });
	std::cout << std::endl;
	for_each(v2.begin(), v2.end(), [=](int x) {std::cout << x << " "; });
	std::cout << std::endl;

}
void test02()
{
	vector<int> v{ 1,3,5,8,2,4,9 };
	auto lower = std::lower_bound(v.begin(), v.end(), 5);//找到大于等于目标元素的
	auto upper = std::upper_bound(v.begin(), v.end(), 5);//找到首个大于目标元素
	cout << *lower << endl;//5
	cout << *upper << endl;//8
}



int main(void)
{

	//test01();//
	test02();//lower_bound 和upper_bound用法

	system("pause");
	return 0;

}
#endif
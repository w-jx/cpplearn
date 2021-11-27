#if 0
#include <iostream>
using namespace std;

// std::pair 用法
//可以利用typedef 简化
using doubleint = pair<int, int>;
typedef pair<int, int> doubleint2;

void printpair(pair<int, int>& p)
{
	cout << "p.first=" << p.first << ",p.second=" << p.second << endl;
}
template<class T1,class T2>
void print_pair(pair<T1, T2>& p)
{
	cout << "p.first=" << p.first << ",p.second=" << p.second << endl;
}
void test01()
{
	pair<int, int> p1;
	p1.first = 10;
	p1.second = 20;
	printpair(p1);

	//直接利用构造函数
	pair<int, int> p2(11,22);
	printpair(p2);

	//利用make_pair
	auto p3 = make_pair(1, 1.1);
	print_pair(p3);

	//using 简化
	auto p4 = doubleint(10, 23);
	print_pair(p4);

	//typedef 简化 
	auto p5 = doubleint2(111, 222);
	print_pair(p5);
	
	auto p6 = make_pair(1, 2);
	print_pair(p6);
	p6.second = 10;
	print_pair(p6);
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif
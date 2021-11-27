#if 1
#include "wjxHeaders.h"
/*



*/
void test01()
{
	vector<int> vret{ 1,10,2,7,8 };
	priority_queue<int> q(vret.begin(),vret.end());
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
}
//
void test02()
{

/*
Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering. 
But because the priority queue outputs largest elements first, the elements that "come before" are actually output last. 
That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.

注意 比较 (Compare) 形参的定义，使得若其第一参数在弱序中先于其第二参数则返回 true 。
但因为 priority_queue 首先输出最大元素，故“先来”的元素实际上最后输出。
即队列头含有按照 比较 (Compare) 所施加弱序的“最后”元素。


greater : true  第一个数>第二个数 ，所以言外之意也就是从大到小排列
但是 第一个元素实际上是最后输出的，所以 top返回的是最小的元素，所以是小顶堆

less: true 第一个数<第二个数，言外之意是从小到大排列
但是 最先的元素 第一个元素 是最后输出的，所以top返回的是最后的最大的元素，所以是大顶堆

*/


	vector<int> vret{ 1,10,2,7,8 };
	priority_queue<int> q(vret.begin(), vret.end());
	cout << q.top()<<endl;//默认的是大顶堆

	priority_queue<int, std::vector<int>, std::greater<> > q2(vret.begin(), vret.end());
	cout << q2.top()<<endl;//greater ->对应的是小顶堆

	priority_queue<int, std::vector<int>, std::less<> > q3(vret.begin(), vret.end());
	cout << q3.top() << endl;//less  ->对应的大顶堆

	
}
class Mycmp {
public:
	bool operator()(pair<string, int>& p1, pair<string, int>& p2)
	{
		return false;
	}
};

bool cmp(pair<string, int>& p1, pair<string, int>& p2)
{
	return false;
}
void test03()
{

	auto mycmp = [](pair<string, int>& p1, pair<string, int>& p2)mutable ->bool  {
		
	};
	priority_queue < pair<string, int>, vector<pair<string, int>>, decltype(mycmp)> col;
	//vector<std::pair<string, int>> v;
	//sort(v.begin(), v.end(), cmp);
}
int main()
{
	//test01();
	test02();
	//test03();
	
	return 0;
}
#endif
#if 0
#include <iostream>
#include <deque>
#define VNAME(value) (#value)//在宏VNAME中，我们使用了#，这个#出现在宏中，表示对后面的变量替换的时候，用双引号""括起来，刚好满足我们的需求。
#define vname VNAME
#include <algorithm>
using namespace std;
/*
双端数组,可以对头端进行插入删除操作
//** 和vector的区别
1.vector头插效率低,数据量越大,效率越低
2.deque 头插速度比vector快
3.访问速度上vector比deque快

迭代器支持随机访问

工作原理:内部有个中控器,存放缓冲区的地址,缓冲区存放真实数据
**/
template <class T>
void printDeque(deque<T>& d,string str)
{
	std::cout << str << ":";
	for (auto iter: d) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}
template <class T>
void insertDeque(deque<T>& d, int begin,int end)
{
	for (int i = begin; i <= end; i++) {
		d.push_back(i);
	}

}
template<class T>
void print(T& a)
{
	std::cout << a << std::endl;
}
int my_sort(int a, int b)
{
	return a > b;
}
//构造函数
void test01()//
{
	deque<int> d1;//默认构造函数
	insertDeque(d1, 0, 3);
	printDeque(d1,VNAME(d1));

	deque<int> d2(d1.begin(), d1.end());//方式2区间方式
	printDeque(d2, VNAME(d2));

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());//同方式2区间方式
	printDeque(d3, VNAME(d3));

	deque<int>d4(3, 2);//参数1元素数量,参数2元素
	printDeque(d4, VNAME(d4));

	deque<int>d5(d1);//拷贝构造函数
	printDeque(d5, VNAME(d5));

	deque<int>d6 = d1;//拷贝构造,重载
	printDeque(d6,VNAME(d6));

}
//赋值操作
void test02()//
{
	deque<int>d1;
	insertDeque(d1, 2, 5);

	deque<int>d2 = d1;//方式1.重载等号
	printDeque(d2, VNAME(d2));

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());//方式2,区间方式
	printDeque(d3, VNAME(d3));
	deque<int>d4;
	d4.assign(5, 1);//方式3 参数1,数量 参数2:元素
	printDeque(d4, VNAME(d4));
}
//大小操作,deque没有容量的概念,capacity()
void test03()//
{	
	deque<int>d;
	deque<int>d_empty;

	insertDeque(d, 1, 4);

	std::cout << "d是否为空:" << d.empty() << ",d_empty是否为空:" << d_empty.empty() << std::endl;

	std::cout << "d的大小:" << d.size() << ",d_empty的大小:" << d_empty.size() << std::endl;

	d.resize(10);//容器变长,用默认值填充
	d_empty.resize(10,5);//可以改变填充的默认值
	printDeque(d, VNAME(d));
	printDeque(d_empty, VNAME(d_empty));
}
//插入和删除
void test04()//
{
	/*两端操作*/
	deque<int> d;
	d.push_back(1);
	d.push_front(2);
	d.push_back(3);
	d.push_front(4);
	printDeque(d, VNAME(d));
	d.pop_front();//头删
	d.pop_back();//尾删
	printDeque(d, VNAME(d));
	/*指定位置操作*/
	auto iter = d.begin();
	iter++;
	auto pos = d.insert(iter, 0);
	printDeque(d, VNAME(d));
	pos = d.insert(pos, 10);
	printDeque(d, VNAME(d));
	pos = d.insert(pos, 3, 8);//参数1,位置,参数2,数量,参数3,元素
	printDeque(d, VNAME(d));

	deque<int> d1;
	insertDeque(d1, 11, 15);
	printDeque(d1, vname(d1));

	d.insert(pos, d1.begin(), d1.end());//无返回值,插入区间的内容
	printDeque(d, vname(d));

	auto begin = d.begin();
	begin++;//指向第二个位置
	auto end = begin + 5;//指向第8个位置
	d.erase(begin, end);//清除指定区间的内容
	printDeque(d, vname(d));

	d.erase(d.begin());//清除指定位置数据
	printDeque(d, vname(d));

	d.clear();//清空

}
//deque 数据存取
void test05()//
{
	deque<int>d;
	insertDeque(d, 3, 5);
	printDeque(d, vname(d));
	print(d.at(1));
	print(d[1]);
	print(d.front());
	print(d.back());
}
//deque排序
void test06()//
{
	deque<int>d;
	d.push_back(2);
	d.push_back(5);
	d.push_back(4);
	d.push_back(3);
	d.push_back(1);
	d.push_back(7);
	printDeque(d, vname(d));
	//sort(d.begin(), d.end(),my_sort);可以加函数实现从大到小,或者从小到大,默认从小到大
	printDeque(d, vname(d));
}

int main(void)
{

	//test01();//构造函数
	//test02();//赋值操作
	//test03();//大小操作
	//test04();//插入和删除
	//test05();//deque 数据存取
	test06();//标准算法排序

	system("pause");
	return 0;

}
#endif
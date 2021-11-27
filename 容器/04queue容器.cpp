#if 0
#include <iostream>
#include <queue>
using namespace std;

/*
queue容器,先进先出,它有两个出口
队列允许一端新增元素,另一端移除元素
队列只有队头 和  队尾可以被外界使用,因此不允许遍历
进数据---push入队  出数据 pop
*/
//构造函数  与 赋值操作
void test01()//
{
	queue<int>q;//默认构造
	
	queue<int>q1(q);//拷贝构造

	queue<int>q2 = q;//赋值操作
}
//数据存取
void test02()//
{
	queue<int>q;
	for (int i = 0; i < 5; i++) {
		q.push(i);//向队尾添加元素
	}
	std::cout << q.back() << std::endl;//返回最后一个元素
	for (int i = 0; i < 5; i++) {
		std::cout << q.front() << " ";//返回第一个元素
		q.pop();//从队头移除第一个元素
	}//输出结果,0,1,2,3,4
}
//大小操作
void test03()//
{
	queue<int>q;
	for (int i = 0; i < 5; i++) {
		q.push(i);//向队尾添加元素
	}
	queue<int>q1;

	std::cout << "q是否为空:" << q.empty() << ",q1是否为空:" << q1.empty() << std::endl;
	std::cout << "q大小:" << q.size() << ",q1大小:" << q1.size() << std::endl;
	
}
struct Node
{
	int val;
	Node* next;
};
//结论：空队列，执行front()会出错
void test04()//
{
	queue<Node*> myqueue;
	//try {
	//	auto temp = myqueue.front();
	//}
	//catch (...) {
	//	cout << "error occur\n";
	//}
	//
	//myqueue.pop();

}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	//test01();//构造函数和赋值
	//test02();//数据存取
	///test03();//大小操作
	test04();//空队列测试
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
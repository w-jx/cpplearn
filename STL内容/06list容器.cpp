#if 0
#include <iostream>
#include <list>
using namespace std;

/*
list容器就是链表,功能是将数据进行链式存储,链表是一种物理存储单元上非连续的存储结构
数据元素的逻辑顺序是通过链表中的指针链接实现的

链表组成:是由一系列结点组成

结点的组成:一个是存储数据元素的数据域,一个是存储下一个结点地址的指针域

STL中的链表是个双向循环链表:

list:优点:
1.采用动态存储分配,不会造成内存的浪费和溢出
2.链表执行插入 和  删除操作十分方便,修改指针就可以了,不需要移动大量元素

缺点:
链表灵活,但是空间(指针域) 和 时间(遍历) 额外消耗比较大

list重要性质,插入操作和删除操作不会造成原来的list迭代器失效,vector是不成立的

STL最重要的两个容器是VECTOR和LIST

*/
void printList(list<int>& l)
{
	for (auto iter : l) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
//list 构造函数,创建list容器,构造函数必须要指明元素类型,否则无法创建对象
void test01()//
{
	list<int> lst;//方式1:模板类实现,对象的默认构造形式
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}

	list<int>lst2(lst.begin(), lst.end());//方式2

	list<int>lst3(5, 1);//方式3 list(n,elem)

	list<int>lst4(lst);//方式4,拷贝构造函数


}
//list 赋值和交换
void test02()//
{
	list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}

	list<int> lst1;
	lst1.assign(lst.begin(), lst.end());//方式1

	list<int> lst2;
	lst2.assign(5, 1);//方式2

	list<int> lst3 = lst;//方式3,重载等于号

	list<int> lst4;
	lst.swap(lst);//方式4,交换元素
	printList(lst);
	printList(lst4);
}
//list 大小操作
void test03()//
{
	list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}

	list<int> lst1;

	std::cout << "list.size()=" << lst.size() << ",lst1.size()=" << lst1.size()
		<< ",lst.empty()=" << lst.empty() << ",lst1.empty()=" << lst1.empty();

	
	lst.resize(6);
	lst1.resize(4, 1);//第二个填充的默认值
	std::cout << "list.size()=" << lst.size() << ",lst1.size()=" << lst1.size()
		<< ",lst.empty()=" << lst.empty() << ",lst1.empty()=" << lst1.empty() << std::endl;;

	printList(lst);
	printList(lst1);

}
//list 插入和删除
void test04()//
{
	//push)back(),尾插
	//pop_back()//尾删

	//push_front()//头插
	//pop_front()//头删
	list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}
	auto iter = lst.begin();
	iter++;
	auto newPos = lst.insert(iter, 7);//方式1,在指定位置插入一个元素,返回值新数据的位置
	printList(lst);
	std::cout << "newPos=" << *newPos << std::endl;

	iter = lst.end();
	iter--;
	lst.insert(iter, 2, 10);//insert(pos,n,elem).无返回值
	printList(lst);

	list<int>lst1;
	lst1.push_back(1);
	printList(lst1);
	lst1.insert(lst1.begin(),lst.begin(), lst.end());//insert(pos,beg,end)
	printList(lst1);

	//lst1.clear();//清空数据
	auto nextPos = lst.erase(newPos, iter);//erase(beg,end),移除指定区间的数据,返回下一个数据的位置
	printList(lst);
	std::cout << "*nextPos=" << *nextPos << std::endl;
	// 0 7(newPos) 1 2 3 10 10 4(iter)   注意前闭后开,移除后的结果为0,4

	auto newPos2 = lst.erase(lst.begin());//移除指定位置的元素,返回下个元素的位置
	std::cout << "*newPos2=" << *newPos2 << std::endl;

	lst1.remove(1);//删除所有与elem值匹配的元素
	printList(lst1);
}
//list 数据存取
void test05()//
{
	list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}

	std::cout << "第一个元素:" << lst.front() << ",最后元素:" << lst.back() << std::endl;
	//std::cout << list[1];//不能通过下标访问元素

	auto iter = lst.begin();//迭代器访问
	std::cout << "value:" << *(++iter) << std::endl;

	//iter = iter + 1;//错误,双向迭代器,不支持随机访问,因为如果支持+1,就支持加2,加3,就可以随机访问了
}
//list 反转和排序
void test06()//
{
	list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}
	printList(lst);
	printf("反转后:\n");
	lst.reverse();
	printList(lst);


	list<int>lst1;
	lst1.push_back(2);
	lst1.push_back(1);
	lst1.push_back(4);
	lst1.push_back(7);
	printList(lst1);
	lst1.sort();
	printList(lst1);
	lst1.sort(myCompare);//利用自己写的函数从大到小排序
	printList(lst1);
	

}



int main(void)
{

	//test01();//构造函数
	//test02();//赋值和交换
	//test03();//list 大小操作
	//test04();//list 插入和删除
	//test05();//list 数据存取
	test06();//反转和排序

	system("pause");
	return 0;

}
#endif
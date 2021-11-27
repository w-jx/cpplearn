#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//for_each第三个 参数的函数
void myPrint(int val) {
	std::cout << val << " ";
}
//打印vector
template<typename T>
void printV(vector<T>& v)
{
	for (auto iter : v) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}
//Teacher 类
class Teacher
{
public:
	Teacher(int age, string name)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	int getAge() 
	{
		return this->m_Age;
	}
	string getName()
	{
		return this->m_Name;
	}
	void setName(string &name)
	{
		this->m_Name = name;
	}
	void setAge(int& age)
	{
		this->m_Age = age;
	}

private:
	int m_Age;
	string m_Name;

};

//------------------------------------------
//遍历
void test01()
{
	vector<int>v;
	v.push_back(19);
	v.push_back(20);
	v.push_back(21);
	v.push_back(22);


	vector<int>::iterator vBegin = v.begin();//起始迭代器
	vector<int>::iterator vEnd = v.end();//起始迭代器
	//while (vBegin != vEnd) {  //方式1
	//	std::cout << *vBegin << std::endl;
	//	vBegin++;
	//}

	//方式2::for循环
	
	//方式3 for_each标准算法
	//for_each(v.begin(), v.end(), myPrint);//

	//迭代器可以用auto关键字
	//for (auto a = v.begin(); a != v.end(); a++) {
	//	std::cout << *a << std::endl;
	//}

}
//vector存放自定义结构类型
void test02()//vector存放自定义结构类型
{
	vector<Teacher>vTeacher;

	Teacher t1(23, "wjx");
	Teacher t2(21, "zj");
	vTeacher.push_back(t1);
	vTeacher.push_back(t2);


	for (auto it = vTeacher.begin(); it != vTeacher.end(); it++)
	{
		std::cout << "name= " << it->getName() << ",age=" << it->getAge() << " ";

	}
	std::cout << std::endl;


}
//vector容器嵌套
void test03()//
{
	vector<int> v1;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i);
	}
	vector<int>v2;
	for (int i = 4; i < 8; i++) {
		v2.push_back(i);
	}
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);

	for (auto it = v.begin(); it != v.end(); it++) {
		
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}
//vector 构造函数
void test04()//
{
	vector<int>v;
	vector<int> v1;//方式1,利用模板
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), myPrint);

	std::cout << std::endl;
	v = vector<int>(v1.begin(), v1.end());//方式2,拷贝
	for_each(v.begin(), v.end(), myPrint);
	//或者这样
	vector<int>v2(v1.begin(), v1.end());
	
	vector<int>v3(10, 1);//方式3,参数1数量,参数2 元素
	std::cout << std::endl;
	for_each(v3.begin(), v3.end(), myPrint);

	vector<int>v4(v2);//构造函数
	std::cout << std::endl;
	for_each(v4.begin(), v4.end(), myPrint);
	
	
}
//赋值操作
void test05()//
{
	vector<int>v1(5, 1);//方式1,重载  =
	vector<int>v2 = v1;
	for_each(v2.begin(), v2.end(), myPrint);

	std::cout << std::endl;
	vector<int>v3(v1.begin(), v1.end());//方式2
	for_each(v3.begin(), v3.end(), myPrint);

	std::cout << std::endl;
	v3.assign(v1.begin(), v1.end());
	printV(v3);
	

	vector<int>v4(5, 2);//方式3,参数1数量,参数2数值
	//for_each(v4.begin(), v4.end(), myPrint);
	v4.assign(4, 3);
	printV(v4);


}
//vector容量和大小
void test06()//
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 3; i++) {
		v2.push_back(i);
	}
	
	std::cout << v1.empty() << std::endl;//判断容器是否为空, true false
	std::cout << v2.empty() << std::endl;

	std::cout << "v1.capacity() =" << v1.capacity() << ",v1.size()=" << v1.size() <<//容量 和大小
		"|v2.capacity() =" << v2.capacity() << ",v2.size()=" << v2.size() << std::endl;
	//capacity()容量,size():元素的个数
	//resize(int num),resize(int num,elem),重新制定容器的长度,容器变长,以默认值填充,容器变短,多余会被删除

	v1.resize(10);//填充
	printV(v1);
	v2.resize(4,10);
	printV(v2);

	
		
}
//vector 插入 和删除
void test07()
{
	//push_back()尾插  pop_pack()尾删
	vector<int>v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
	}
	printV(v1);
	auto iter = v1.begin();//插入,方式1,在迭代器指定位置添加元素
	v1.insert(iter, 10);
	printV(v1);

	iter = v1.begin();//迭代器使用过以后要重新指定
	iter++;
	v1.insert(iter, 3, 9);//方式2,在迭代器指定位置添加 指定数量的元素
	printV(v1);

	/* 删除 */
	iter = v1.begin();
	auto iter_end = iter + 3;
	v1.erase(iter, iter_end);//删除 两个迭代器之间的所有元素,注意:不包括最后一个
	printV(v1);

	/*清空迭代器*/
	v1.erase(v1.begin(), v1.end());//v1.end()是最后一个元素的下一个迭代器
	v1.clear();
	printV(v1);
}
//vector数据存取
void test08()
{
	vector<int>v;
	for (int i = 10; i > 7; i--) {
		v.push_back(i);
	}
	printV(v);

	for (auto i = 0; i < v.size(); i++) {//方式1
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;

	for (auto i = 0; i < v.size(); i++) {//方式2
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "第一个元素:" << v.front() << std::endl;
	std::cout << "最后一个元素:" << v.back() << std::endl;

}
//vector容器互换
void test09()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i);
	}
	for (int i = 4; i < 8; i++) {
		v2.push_back(i);
	}
	printV(v1);
	printV(v2);

	v1.swap(v2);
	printV(v1);
	printV(v2);

	//利用swap收缩内存
	v1.resize(100000);
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	vector<int>(v2).swap(v1);//匿名对象交换
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;




	
}
//vector容器预留空间
void test10()
{
	//预留空间的目的是动态扩展容量的扩展次数
	vector<int>v;
	int num = 0;
//	int* p = &v[0];//这样会报错,因为这时候无v[0]
	int* p =nullptr;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {//如果指针指向的不是容器的首元素,那么就让它指向首元素,说明扩展了,扩展次数加1
			p = &v[0];
			num++;
		}
	}
	
	std::cout << num << std::endl;//输出结果为24

	vector<int>v2;
	v2.reserve(10000);//预留n个元素的长度,预留的位置不进行初始化,元素也不可访问
	num = 0;
	//	int* p = &v[0];//这样会报错,因为这时候无v[0]
	p = nullptr;
	for (int i = 0; i < 10000; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {//如果指针指向的不是容器的首元素,那么就让它指向首元素,说明扩展了,扩展次数加1
			p = &v2[0];
			num++;
		}
	}
	std::cout << num << std::endl;//输出结果为1



}
int main(void)
{

	//test01();//遍历
	//test02();////vector存放自定义结构类型
	//test03();//vector嵌套
	//test04();//构造函数
	//test05();//赋值操作
	//test06();//vector容量和大小
	//test07();//vector插入和删除
	//test08();//vector数据存取操作
	//test09();//vector容器互换
	//test10();//vector容器预留空间
	system("pause");
	return 0;

}
#endif
#if 0
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*

stack容器的接口很少,无法遍历,"先进后出"
*/
template<class T>
void printStack(stack<T>& s)
{
	//for (auto iter : s) {
	//	std::cout << s << " ";
	//}
	//std::cout<<std::endl;
	//stack不能遍历
}

//构造函数 与 赋值操作
void test01()//
{
	stack<int> s;//默认构造

	for (int i = 0; i < 5; i++) {
		s.push(i);
	}
	//printStack(s);

	stack<int>s1(s);//拷贝构造

	stack<int>s3 = s;//重载等号赋值
	
}
//数据存取
void test02()//
{
	//stack<int> s;
	//for (int i = 0; i < 5; i++) {
	//	s.push(i);
	//}
	//stack<int>s1;
	//std::cout << s.size() << std::endl;
	////std::cout << s.top() << std::endl;
	////std::cout << s.top() << std::endl;
	//for (int i = 0; i < 5; i++) {
	//	s1.push(s.top());
	//	std::cout << s.top() << " ";
	//	s.pop();//移除栈顶元素
	//}
	//std::cout << std::endl;
	//std::cout << s1.top() << std::endl;


	std::cout << "-----------------------------" << std::endl;
	
	stack<int>s2;
	for (int i = 0; i < 5; i++) {
		s2.push(i);
	}
	stack<int>s3;
	vector<int>v;
	for (int i = 0; i < 5; i++) {
		v.push_back(s2.top());
		s2.pop();
	}
	for (int i = v.size()-1; i >= 0; i--) {
		s3.push(v[i]);
	}
	std::cout << s3.top() << std::endl;;




}
//大小操作
void test03()//
{
	stack<int> s;
	stack<int>s1;
	s.push(2);
	s.push(3);
	std::cout << "s是否为空:" << s.empty() << ",s1是否为空:" << s1.empty() << std::endl;

	std::cout << "s的大小:" << s.size() << ",s1大小:" << s1.size() << std::endl;

	
}

void test04()//
{

}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	//test01();//构造函数
	//test02();//数据存取
	test03();//大小操作
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
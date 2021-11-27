#include <iostream>
#include <boost/coroutine/all.hpp>
 
using namespace boost::coroutines;
 
//coroutine函数
void cooperative(coroutine<void>::push_type &sink)
{
	std::cout << "Hello";
 
	//之所以能够执行是因为重载了操作符()
	//返回main()函数继续运行
	sink();
 
	std::cout << "world";
 
	//执行完毕，返回main继续执行
}
int main()
{
	//c++11新特性：统一初始化
	//source对象由于是pull_type类型，所以会马上调用cooperative, push_type类型不会立即执行
	coroutine<void>::pull_type source{ cooperative };
	
	std::cout << ", ";
 
	//返回cooperative函数继续执行
	source();
 
	std::cout << "!";
 
	std::cout << "\n";
}
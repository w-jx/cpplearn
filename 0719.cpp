#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test01()
{
/*
iostream:读写流
fstream:读写命名文件
sstream:读写内存string对象类型
*/
	auto old_state = cin.rdstate();//记住cin当前状态
	cin.clear();//使能cin
	//std::cout << old_state << std::endl;

	std::cout << "hi!" << endl;//输出 hi  加 换行,刷新缓冲区
	std::cout << "hi!" << flush;//输出 hi  刷新缓冲区
	std::cout << "hi!" << ends;//输出 hi  加一个空字符 刷新缓冲区

}
int main()
{

	test01();


	system("pause");
	return 0;
}
#endif
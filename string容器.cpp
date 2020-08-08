#if 1
#include <iostream>
#include <algorithm>
using namespace std;

void printS(const char s)
{
	std::cout << s;
}
void printString(string& s)
{
	std::cout << s << std::endl;
}
//构造函数
void test01()//
{
	//string s1 = string();//空的
	//printString(s1);

	char* s = (char *)"wjx";  //用const char*字符串初始化`string(const char* s)
	string s2 = string(s);
	//printString(s2);
	//for_each(s2.begin(), s2.end(), printS);

	//string s3 = string(s2);
	//printString(s3);

	string s4 = string(10, 'a');
	printString(s4);

}
//赋值操作
void test02()//
{
	string s;

	const char* s1 = "wjx";//方式1
	s = s1;
	printString(s);

	string s2 = "wjx2";//方式2
	s = s2;
	printString(s);

	char s3 = 'c';//方式3
	s = s3;
	printString(s);

	const char* s4 = "wjx4";//方式4
	s.assign(s4);
	printString(s);

	const char* s5 = "wjx5dksdjksdjksdjksjdksjd";//方式5
	s.assign(s5, 4);
	printString(s);

	string s6 = "wjx6";//方式6
	s.assign(s6);
	printString(s);

	s.assign(5, 'w');//方式7
	printString(s);


	
}
//字符串拼接
void test03()//
{
	string s = "wjx";
	
	const char* s1 = "g";//方式1
	s += s1;
	printString(s);

	const char s2 = '-o';//方式2
	s += s2;
	printString(s);

	string s3 = " to";//方式3
	s += s3;
	printString(s);

	const char* s4 = " bed";//方式4
	s.append(s4);
	printString(s);

	string s5 = ",and";
	s.append(s5);
	printString(s);

	string s6 = " sleepdjshdjshdkjhsdkjhsdkhskdhskdh";//方式6,从指定位置的指定数量字符
	s.append(s6, 0, 6);//从0位置的5个字符
	printString(s);


}
//字符串查找和替换
void test04()//
{
	//查找--指定字符串是否存在  存在返回位置,不存在返回-1 4294967295
	//string s = "WjxIsMyName_WjxIsMyName";
	string s = "WjxIsMyName";

	//string s1 = "Wjx";//方式1:从指定位置开始找
	//std::cout << s.find(s1, 0)  << std::endl;

	const char* s2 = "jx";//方式2,替换成char*字符串
	std::cout << s.find(s2, 0) << std::endl;
	
	const char* s3 = "Is";//方式3,从0位置的前5个字符查找出现的第一次位置
	std::cout << s.find(s3, 0,2) << std::endl;//这边是没找到??????

	//const char s4 = 'W';//方式4,从指定位置查找字符c第一次出现的位置,
	//std::cout << s.find(s4, 0) << std::endl;

	//string s5 = "Name";//方式5,右侧查找,指定字符串最后一次位置,从指定位置开始
	//std::cout << s.rfind(s5, 0) << std::endl;
	
	
	
	//替换 在指定的位置替换字符串
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
	//test02();//赋值操作
	//test03();//字符串拼接
	test04();//字符串查找和替换
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
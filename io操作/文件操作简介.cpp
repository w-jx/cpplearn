#if 0
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
头文件  fstream
文件分类:1.文本文件,以文本的ASCII码存储  2.二进制文件,文本以文本的二进制形式存储
操作文件三大类:
1.ofstream写		2.ifstream读		3.fstream读写

打开方式:  可以利用 | 配合使用多种该方式 ios::binary |ios::out二进制方式写文件
ios::in	读
ios::out 写
ios::ate 初始位置 文件尾
ios::app 追加方式写
ios::trunc	如果文件存在先删除,在创建
ios::binary 二进制方式

*/
//读写文本文件  写
void test01()//
{
	ofstream ofs;
	ofs.open("1.txt", ios::trunc);

	ofs << "姓名:张三" << endl;
	ofs << "性别:男" << endl;
	ofs.close();
}
//读文本文件
void test02()//
{
	ifstream ifs;
	ifs.open("1.txt", ios::in);
	if (!ifs.is_open()) {
		return;
	}

	//char* s = new char[1024];	//方式1
	//while (ifs >> s) 
	//{
	//	cout << s << endl;;
	//}
	//delete s;//注意一个事情,这个数组大小是1024可以完整输出,但是我人为改成5触发一个断点

	//char buf[1024];	//方式2
	//memset(buf, 0, 1024);
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//string buf;//方式3
	//while (getline(ifs, buf))//这个getline需要添加string头文件
	//{
	//	cout << buf << endl;
	//}
	
	char c;

	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();

	
}

void test03()//
{

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

	//test01();////写文本文件
	test02();////读文本文件
	//test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
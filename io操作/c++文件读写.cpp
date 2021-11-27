#if 0
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <sys/stat.h>  //在Windows下也有
using namespace std;
//c++ 文件读写
/*
* 写文件--ofstream,读文件ifstream，读写：fstream
mode	-	指定打开模式。它是位掩码类型，定义下列常量：
常量	解释
app	每次写入前寻位到流结尾
binary	以二进制模式打开
in	为读打开
out	为写打开
trunc	在打开时舍弃流的内容
ate	打开后立即寻位到流结尾


*/

void test01()//ofstream 写文件
{
	ofstream ofs;
	ofs.open("test.txt", ofs.out);
	ofs << "hello,world" << endl;
	ofs << "sdsdasd" << endl;
	ofs << 111 << endl;
	ofs.close();
}
void test02()//读文件
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	string str;
	
	while(ifs>>str)
		cout << str << endl;
	ifs.close();
}
void test03() //获取文件大小
{
	ifstream ifs("test.txt", ios::in);
	if (ifs.is_open()) {

		ifs.seekg(0, SEEK_END);
		int size = ifs.tellg();
		ifs.close();
		cout << "fise.size()=" << size << endl;
	}
}
void test04()//C语言获取文件大小的方式1，限制2G
{
	FILE* fp;
	fopen_s(&fp, "test.txt", "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	cout << "file.size()=" << size << endl;
	fclose(fp);
}
//利用stat来读取
void test05()
{
	struct stat sb;
	stat("test.txt", &sb);
	int size = sb.st_size;
	switch (sb.st_mode & S_IFMT) {
	case S_IFREG:cout << "it's a reg file\n"; break;
	case S_IFDIR:cout << "it's a dir\n"; break;
	case S_IFCHR:cout << "its a character device\n"; break;
	default:break;
		
	}
	cout << "size=" << size << endl;
}
void test06()//C语言读写文件
{
	FILE* fp;
	int ret=fopen_s(&fp, "test.txt", "rb");
	if (ret == 0) {

		char buf[1024] = { 0 };//字符串初始化0，不初始化会出现"烫烫烫"
		while (fread(buf, sizeof(char), 1024, fp)) {
	
			cout << buf << endl;
		}
			

		fclose(fp);

	}
	else {
		cout << ret << endl;
		cout << "file open fail\n";
	}

		
	return;
	
	
}
int main(void)
{
	//test01();//写文件尝试
	//test02();//读文件
	//test03();//获取文件大小
	//test04();//C 获取文件大小--方式1
	//test05();//C利用stat获取文件大小和类型
	test06();//读写文件，C
	system("pause");
	return 0;
}
#endif
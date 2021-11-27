#if 0
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <sys/stat.h>  //��Windows��Ҳ��
using namespace std;
//c++ �ļ���д
/*
* д�ļ�--ofstream,���ļ�ifstream����д��fstream
mode	-	ָ����ģʽ������λ�������ͣ��������г�����
����	����
app	ÿ��д��ǰѰλ������β
binary	�Զ�����ģʽ��
in	Ϊ����
out	Ϊд��
trunc	�ڴ�ʱ������������
ate	�򿪺�����Ѱλ������β


*/

void test01()//ofstream д�ļ�
{
	ofstream ofs;
	ofs.open("test.txt", ofs.out);
	ofs << "hello,world" << endl;
	ofs << "sdsdasd" << endl;
	ofs << 111 << endl;
	ofs.close();
}
void test02()//���ļ�
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	string str;
	
	while(ifs>>str)
		cout << str << endl;
	ifs.close();
}
void test03() //��ȡ�ļ���С
{
	ifstream ifs("test.txt", ios::in);
	if (ifs.is_open()) {

		ifs.seekg(0, SEEK_END);
		int size = ifs.tellg();
		ifs.close();
		cout << "fise.size()=" << size << endl;
	}
}
void test04()//C���Ի�ȡ�ļ���С�ķ�ʽ1������2G
{
	FILE* fp;
	fopen_s(&fp, "test.txt", "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	cout << "file.size()=" << size << endl;
	fclose(fp);
}
//����stat����ȡ
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
void test06()//C���Զ�д�ļ�
{
	FILE* fp;
	int ret=fopen_s(&fp, "test.txt", "rb");
	if (ret == 0) {

		char buf[1024] = { 0 };//�ַ�����ʼ��0������ʼ�������"������"
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
	//test01();//д�ļ�����
	//test02();//���ļ�
	//test03();//��ȡ�ļ���С
	//test04();//C ��ȡ�ļ���С--��ʽ1
	//test05();//C����stat��ȡ�ļ���С������
	test06();//��д�ļ���C
	system("pause");
	return 0;
}
#endif
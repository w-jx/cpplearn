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
//���캯��
void test01()//
{
	//string s1 = string();//�յ�
	//printString(s1);

	char* s = (char *)"wjx";  //��const char*�ַ�����ʼ��`string(const char* s)
	string s2 = string(s);
	//printString(s2);
	//for_each(s2.begin(), s2.end(), printS);

	//string s3 = string(s2);
	//printString(s3);

	string s4 = string(10, 'a');
	printString(s4);

}
//��ֵ����
void test02()//
{
	string s;

	const char* s1 = "wjx";//��ʽ1
	s = s1;
	printString(s);

	string s2 = "wjx2";//��ʽ2
	s = s2;
	printString(s);

	char s3 = 'c';//��ʽ3
	s = s3;
	printString(s);

	const char* s4 = "wjx4";//��ʽ4
	s.assign(s4);
	printString(s);

	const char* s5 = "wjx5dksdjksdjksdjksjdksjd";//��ʽ5
	s.assign(s5, 4);
	printString(s);

	string s6 = "wjx6";//��ʽ6
	s.assign(s6);
	printString(s);

	s.assign(5, 'w');//��ʽ7
	printString(s);


	
}
//�ַ���ƴ��
void test03()//
{
	string s = "wjx";
	
	const char* s1 = "g";//��ʽ1
	s += s1;
	printString(s);

	const char s2 = '-o';//��ʽ2
	s += s2;
	printString(s);

	string s3 = " to";//��ʽ3
	s += s3;
	printString(s);

	const char* s4 = " bed";//��ʽ4
	s.append(s4);
	printString(s);

	string s5 = ",and";
	s.append(s5);
	printString(s);

	string s6 = " sleepdjshdjshdkjhsdkjhsdkhskdhskdh";//��ʽ6,��ָ��λ�õ�ָ�������ַ�
	s.append(s6, 0, 6);//��0λ�õ�5���ַ�
	printString(s);


}
//�ַ������Һ��滻
void test04()//
{
	//����--ָ���ַ����Ƿ����  ���ڷ���λ��,�����ڷ���-1 4294967295
	//string s = "WjxIsMyName_WjxIsMyName";
	string s = "WjxIsMyName";

	//string s1 = "Wjx";//��ʽ1:��ָ��λ�ÿ�ʼ��
	//std::cout << s.find(s1, 0)  << std::endl;

	const char* s2 = "jx";//��ʽ2,�滻��char*�ַ���
	std::cout << s.find(s2, 0) << std::endl;
	
	const char* s3 = "Is";//��ʽ3,��0λ�õ�ǰ5���ַ����ҳ��ֵĵ�һ��λ��
	std::cout << s.find(s3, 0,2) << std::endl;//�����û�ҵ�??????

	//const char s4 = 'W';//��ʽ4,��ָ��λ�ò����ַ�c��һ�γ��ֵ�λ��,
	//std::cout << s.find(s4, 0) << std::endl;

	//string s5 = "Name";//��ʽ5,�Ҳ����,ָ���ַ������һ��λ��,��ָ��λ�ÿ�ʼ
	//std::cout << s.rfind(s5, 0) << std::endl;
	
	
	
	//�滻 ��ָ����λ���滻�ַ���
}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	//test01();//���캯��
	//test02();//��ֵ����
	//test03();//�ַ���ƴ��
	test04();//�ַ������Һ��滻
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
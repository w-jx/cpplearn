#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test01()
{
/*
iostream:��д��
fstream:��д�����ļ�
sstream:��д�ڴ�string��������
*/
	auto old_state = cin.rdstate();//��סcin��ǰ״̬
	cin.clear();//ʹ��cin
	//std::cout << old_state << std::endl;

	std::cout << "hi!" << endl;//��� hi  �� ����,ˢ�»�����
	std::cout << "hi!" << flush;//��� hi  ˢ�»�����
	std::cout << "hi!" << ends;//��� hi  ��һ�����ַ� ˢ�»�����

}
int main()
{

	test01();


	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;
//std::transform
/*
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first,
					UnaryOperation unary_op );

ת�������֣�һԪת���Ͷ�Ԫת����
һԪת���Ƕ�����������Χ�ڵ�ÿ��Ԫ����ĳ��һԪ����������һ�������ֻ�漰һ������ת�������������
��4��������ǰ2��ָ��Ҫת������������ֹ��Χ����3�������ǽ�������������ʼλ�ã���4��������һԪ���㡣


��Ԫת���Ƕ���������������Χ�ڵ�ÿ��Ԫ������Ԫ����������һ��������漰��������ת������������
��5��������ǰ2��ָ������ת���ĵ�1����������ֹ��Χ����3��������ת���ĵ�2����������ʼλ�ã�
��4�������ǽ�������������ʼλ�ã���5�������Ƕ�Ԫ���㡣
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
					OutputIt d_first, BinaryOperation binary_op );
 
 
*/
//���ַ�����Сдת��--һԪת��
void test01()
{
	std::string str = "Hello, World!";
	std::string strUpper(str.length(), ' ');//����
	std::transform(str.begin(), str.end(), strUpper.begin(), std::toupper);//һԪת��
	cout << strUpper << endl;//������ HELLO, WORLD!

	std::transform(str.begin(), str.end(), str.begin(), std::tolower);
	cout << str << endl;//������hello, world!
}
//��������Ԫ�طֱ����----��Ԫת��
void test02()
{
	
	std::vector<int> v1 = { 10, 20, 30, 40, 50 };
	std::vector<int> v2 = { 1, 2, 3, 4, 5 };
	std::vector<int> result(5);//������

	std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), std::plus<int>());

	for (int i : result) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;

}
int main(void)
{
	//test01();//���ַ�����Сдת�� һԪת��
	test02();//��������Ԫ�طֱ���� ��Ԫת��
	system("pause");
	return 0;
}
#endif
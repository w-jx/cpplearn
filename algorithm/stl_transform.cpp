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

转换有两种：一元转换和二元转换。
一元转换是对容器给定范围内的每个元素做某种一元运算后放在另一个容器里。只涉及一个参与转换运算的容器。
有4个参数，前2个指定要转换的容器的起止范围，第3个参数是结果存放容器的起始位置，第4个参数是一元运算。


二元转换是对两个容器给定范围内的每个元素做二元运算后放在另一个容器里。涉及两个参与转换运算容器。
有5个参数，前2个指定参与转换的第1个容器的起止范围，第3个参数是转换的第2个容器的起始位置，
第4个参数是结果存放容器的起始位置，第5个参数是二元运算。
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
					OutputIt d_first, BinaryOperation binary_op );
 
 
*/
//对字符串大小写转换--一元转换
void test01()
{
	std::string str = "Hello, World!";
	std::string strUpper(str.length(), ' ');//构造
	std::transform(str.begin(), str.end(), strUpper.begin(), std::toupper);//一元转换
	cout << strUpper << endl;//输出结果 HELLO, WORLD!

	std::transform(str.begin(), str.end(), str.begin(), std::tolower);
	cout << str << endl;//输出结果hello, world!
}
//两个数组元素分别相加----二元转换
void test02()
{
	
	std::vector<int> v1 = { 10, 20, 30, 40, 50 };
	std::vector<int> v2 = { 1, 2, 3, 4, 5 };
	std::vector<int> result(5);//保存结果

	std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), std::plus<int>());

	for (int i : result) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;

}
int main(void)
{
	//test01();//对字符串大小写转换 一元转换
	test02();//两个数组元素分别相加 二元转换
	system("pause");
	return 0;
}
#endif
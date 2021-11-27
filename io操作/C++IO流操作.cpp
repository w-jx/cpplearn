#if 0
#include "wjxHeaders.h"


//可以发现，对于字符和字符串的操作，很简单，输出结果正常
void test01()
{
	string str;
	char ch;

	//cin >> str;
	//cin >> ch;
	//cout << "str=" <<str<< endl;
	//cout << "ch=" << ch<<endl; //输出 结果正常

	cin >> str >> ch;
	cout << "str=" << str << ",ch=" << ch << endl;//输出结果也是正常的
}

void test02()
{
	int n = 0;
	while (cin >> n) {
		cout << "n=" << n<<endl;
	}

}
void test03()
{

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#endif
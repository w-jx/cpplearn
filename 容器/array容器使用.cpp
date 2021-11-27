#if 0
#include <iostream>
#include <array>
using namespace std;
void test01()
{
	array<int, 10> arr;
	
	
	

	[=](array<int, 10>& a) {
		auto i = 2;
		for (int i = 0; i < 10; i++) {
			a.at(i) = 5;
		}
		
		for (int i=1;i<10;i++)
		{
			cout << a[i] << " ";
		}
		cout<<endl;
	}(arr);



	[]() {//用初始化列表初始化
		array<int, 10> arr{ 1,3,5,7,9 };

		for (const auto iter : arr) {
			cout << iter << " ";
		}
		cout << endl;

	};


	[]() {//用初始化列表初始化
		array<int, 10> arr;

		for (const auto iter : arr) {
			cout << iter << " ";
		}
		cout << endl;

	};
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif
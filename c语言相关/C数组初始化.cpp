#if 0
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//结论：数组初始化所有元素为0
//类似 int arr[2]={-1} 只是让数组第一个元素为-1,其余的还是0
void printarray(int* arr, int size)
{
	size_t i = 0;
	for (; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}
void printarray(int** arr, int size)
{

}
void test01()
{
	int arr[10] = { -1 };
	//cout << sizeof(arr)/sizeof(int) << endl; //得到数组长度
	//printarray(arr, sizeof(arr) / sizeof(int));

	int arr2[2][10] = {0 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr2[i][j] << " ";
		}
	}
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif
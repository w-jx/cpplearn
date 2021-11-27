#include <iostream>
#include <algorithm>
using namespace std;

//在子函数中为指针分配空间，参数列表中要使用指针的引用。


//这个函数是给数组开辟空间，并初始化的
//T* & ,和T *区别
template<typename T>
void make_array(T *array,size_t len,const T & init_val=T())
{
	array = new T[len];
	for(int i = 0;i<len;++i) {
		array[i]=init_val;
	}	
}
void test02()
{
	int *arr;
	make_array(arr,10,10);
	for(int i=0;i<10;++i) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	delete[] arr;
}


void test01()
{
	int* a = nullptr;
	int* b = a;

	a = new int(5);

	//cout << *a << endl;
	cout << *b << endl;//猜测会不会出错,答案会，b=nullptr

	delete a;
}
int main()
{
	test02();

	return 0;
}

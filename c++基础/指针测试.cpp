#include <iostream>
#include <algorithm>
using namespace std;

//���Ӻ�����Ϊָ�����ռ䣬�����б���Ҫʹ��ָ������á�


//��������Ǹ����鿪�ٿռ䣬����ʼ����
//T* & ,��T *����
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
	cout << *b << endl;//�²�᲻�����,�𰸻ᣬb=nullptr

	delete a;
}
int main()
{
	test02();

	return 0;
}

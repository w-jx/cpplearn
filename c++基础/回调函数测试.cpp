#if 0
#include <iostream>
#include <vector>
using namespace std;



//template<class  T>
//typedef T(* cb)(T&&, T&&) ;
//typedef ��֧�ִ�����ģ��ĺ���ָ�붨��




template<typename T>
using mycb = T(*)(T&&, T&&);

template<typename T>
T myadd(T&& n1, T&& n2)
{
	return n1 + n2;
}


template<typename T>
T operator_nums(T&& n1, T&& n2, T(*callback)(T&&, T&&))
{
	//return callback( forward<T>(n1),forward<T> (n2));//����forward�޷�ͨ��
	return callback(move(n1), move(n2));//ͨ������
	//return callback(n1, n2);
	/*
��T (T &&,T &&)��: �޷������� 2 �ӡ�T��ת��Ϊ��T &&��	cpplearn	

�������ۣ���ߴ�������Ҫ��ֵ
	*/
}

template<typename T>
T operator_nums2(T&& n1, T&& n2, mycb<T> cb)
{
	return cb(move(n1), move(n2));//ͨ������
}
void test01()
{
	//int a = 10;
	//int b = 20;
	//cout << myadd(10, 20) << endl;//������ĺ������ö���


	//cout << operator_nums(21, 9, myadd)<<endl;
	cout << operator_nums2(21, 9, myadd) << endl;



}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif
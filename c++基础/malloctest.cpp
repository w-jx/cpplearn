#if 0
#include <iostream>
#include <vector>
using namespace std;

int* a3;
void test01()
{
	int* a = (int*)malloc(sizeof(int) * 10);
	/*int* a = (int*)malloc(sizeof(int) );*/
	for (size_t i = 0; i < 10; i++)
		a[i] = i;
	//for (size_t i = 0; i < 10; i++)
	//	cout << a[i] << "\t";
	cout << endl;

	a = (int*)realloc(a, sizeof(int) * 20);
	for (size_t i = 0; i < 10; i++)
		a[i + 10] = i + 10;
	for (size_t i = 0; i < 20; i++)
		cout << a[i] << "\t";

	free(a);
}
/*malloc �� new ������
1.�����ڴ�����λ��
	malloc ----��
	new   -----���ɴ洢�������������Ƕѣ��������Ǿ�̬�洢����
2.�������Ͱ�ȫ��
	malloc-----����void*,��Ҫǿ������ת��
	new  -------�������������ƥ��
3.�ڴ����ʧ�ܵķ���ֵ
	malloc -----ʧ�ܷ���NULL
	new -------�������᷵��NULL���׳�bad_alloc�쳣
		try{
			int *a = new int(10);
		}
		catch(bad_alloc)
		{
			....
		}

4.�Ƿ���Ҫָ���ڴ��С
	new ����
	malloc ��Ҫ
5.�Ƿ���ù������������
	ʹ��new:
		1.����operator new������������operator new[])����һ���㹻��ģ�ԭʼ�ģ�δ�������ڴ�ռ�
		�Ա��ڴ洢�ض����͵Ķ���
		2.������������Ӧ�Ĺ��캯���Թ������Ϊ�䴫���ʼ
		3.������ɣ�����ָ��ö����ָ��
	��deleteʱ��
		1.���ö������������
		2.����������operator delete����operator delete[])�����ͷ��ڴ�ռ�

	malloc���ᣬ��˲��ʺ���mallloc����C++������Ҫ���������������

6.������Ĵ���
	new:
		T *ptr =new T[10];// ����10��T����
		delete[] ptr;//�ͷŶ���

	malloc:
		T *ptr = (T*)malloc(sizeof(T)*10);//��Ҫ�ֶ��ƶ�����Ĵ�С

7.new �� malloc �Ƿ�����໥����
	����operator new �� operator delete�ļ�ʵ�֣�
	void * operator new (sieze_t size)
	{
		if(void * mem = malloc(size)
			return mem;
		else
			throw bad_alloc();
	}
	void operator delete(void *mem) noexcept
	{
		free(mem);
	}
	���Կ����ǻ���malloc�ģ�����malloc����ȥ����new

8.�Ƿ��������
	operator new �� operator delete�������أ���׼�����8�����ذ汾

	//��Щ�汾�����׳��쳣
	void * operator new(size_t);
	void * operator new[](size_t);
	void * operator delete (void * )noexcept;
	void * operator delete[](void *0��noexcept;
//��Щ�汾��ŵ���׳��쳣
	void * operator new(size_t ,nothrow_t&) noexcept;
	void * operator new[](size_t, nothrow_t& );
	void * operator delete (void *,nothrow_t& )noexcept;
	void * operator delete[](void *0,nothrow_t& ��noexcept;

	malloc/free������������
9.�ܹ�ֱ�۵����·����ڴ�
	malloc�����ڴ淢�ֲ�������������realloc���������ڴ����·�����ʵ���ڴ������
	1.�жϵ�ǰ��ָ����ָ����ڴ��Ƿ����㹻�������ռ�
		1.����У�ԭ������ɷ�����ڴ��ַ�����ҷ���ԭ���ĵ�ַָ��
		2.���û�У��ռ䲻�����Ȱ�����ָ���Ĵ�С����ռ䣬��ԭ������
		  ��ͷ��β�������·�����ڴ�����Ȼ���ͷ�ԭ�����ڴ�����

	newû����������ʩ

* */
int const* retptr()
{
	int* a = (int*)malloc(sizeof(int) * 2);
	a[0] = 10;
	a[1] = 20;
	return &a[1];
}
void test02()
{
	int const* ptr = retptr();
	ptr--;
	cout << "ptr = " << *ptr << endl;
	//free((void *)ptr);
}
void test03()
{

	int* b = static_cast<int*>(malloc(sizeof(int)));
	int c = 10;
	b = &c;
	cout << "b=" << *b << endl;

	//����ע�⵽a��û�з����ڴ�
	a3 = b;
	cout << "a3=" << *a3 << endl;



}
int main(void)
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
#endif
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
/*malloc 和 new 的区别
1.申请内存所在位置
	malloc ----堆
	new   -----自由存储区（不仅可以是堆，还可以是静态存储区）
2.返回类型安全性
	malloc-----返回void*,需要强制类型转换
	new  -------返回类型与对象匹配
3.内存分配失败的返回值
	malloc -----失败返回NULL
	new -------根本不会返回NULL，抛出bad_alloc异常
		try{
			int *a = new int(10);
		}
		catch(bad_alloc)
		{
			....
		}

4.是否需要指定内存大小
	new 无需
	malloc 需要
5.是否调用构造和析构函数
	使用new:
		1.调用operator new函数（数组是operator new[])分配一块足够大的，原始的，未命名的内存空间
		以便于存储特定类型的对象
		2.编译器运行相应的构造函数以构造对象，为其传入初始
		3.构造完成，返回指向该对象的指针
	当delete时：
		1.调用对象的析构函数
		2.编译器调用operator delete（或operator delete[])函数释放内存空间

	malloc不会，因此不适合用mallloc处理C++里面需要构造和析构的类型

6.对数组的处理
	new:
		T *ptr =new T[10];// 分配10个T对象
		delete[] ptr;//释放对象

	malloc:
		T *ptr = (T*)malloc(sizeof(T)*10);//需要手动制动数组的大小

7.new 和 malloc 是否可以相互调用
	这是operator new 和 operator delete的简单实现：
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
	可以看出是基于malloc的，但是malloc不能去调用new

8.是否可以重载
	operator new 和 operator delete可以重载，标准库就有8个重载版本

	//这些版本可能抛出异常
	void * operator new(size_t);
	void * operator new[](size_t);
	void * operator delete (void * )noexcept;
	void * operator delete[](void *0）noexcept;
//这些版本承诺不抛出异常
	void * operator new(size_t ,nothrow_t&) noexcept;
	void * operator new[](size_t, nothrow_t& );
	void * operator delete (void *,nothrow_t& )noexcept;
	void * operator delete[](void *0,nothrow_t& ）noexcept;

	malloc/free并不允许重载
9.能够直观地重新分配内存
	malloc分配内存发现不够，可以利用realloc函数进行内存重新分配以实现内存的扩充
	1.判断当前的指针所指向的内存是否有足够的连续空间
		1.如果有：原地扩大可分配的内存地址，并且返回原来的地址指针
		2.如果没有，空间不够，先按照新指定的大小分配空间，将原有数据
		  从头到尾拷贝的新分配的内存区域，然后释放原来的内存区域

	new没有这样的设施

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

	//我们注意到a并没有分配内存
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
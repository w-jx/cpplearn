#if 0
#include "wjxHeaders.h"

template<typename T> 
class Smartptr
{
public:
	Smartptr() ;//构造一个空白智能指针
	Smartptr(T&& arg);
	Smartptr(T* p); //Smartprt<int> p(new int(2))
	Smartptr(Smartptr<T> const& oldptr);//smartptr<int> q(p)
	Smartptr<T>& operator=(Smartptr<T> const& oldptr);//重载=
	~Smartptr();
public:
	T operator*();//为了把智能指针当成普通指针定义解引用
	T* operator->();//定义取成员操作
	T* operator+(int i);//定义指针 加一个常数
	//int operator-(Smartptr<T> &t1, Smartptr<T> &t2);
	int use_count();
	T* get();

private:
	T* ptr;//底层指针
	int* _use_count;//保存当前对象被多少指针引用计数
};
template<typename T>
Smartptr<T> make_smart(T args)
{
	Smartptr<T> smartptr(new T(args));
	return smartptr;

}
void test01()
{
	Smartptr<int> mysp(10);
	cout << mysp.use_count() << endl;
	auto p = mysp;
	cout << mysp.use_count() << endl;
	cout << *mysp << endl;
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}


template<typename T>
Smartptr<T>::Smartptr()
{
	this->_use_count = new int(0);
}


template<typename T>
Smartptr<T>::Smartptr(T&& arg)
{
	ptr = new T(arg);
	try {
		this->_use_count = new int(1);
	}
	catch (...)//接收所有异常
	{//申请失败 释放真实指针和引用计数的内存
		delete ptr;
		ptr = nullptr;

		delete _use_count;
		_use_count = nullptr;

	}
}

template<typename T>
Smartptr<T>::Smartptr(T* p)
{
	ptr = p;
	try {
		this->_use_count = new int(1);
	}
	catch (...)//接收所有异常
	{//申请失败 释放真实指针和引用计数的内存
		delete ptr;
		ptr = nullptr;

		delete _use_count;
		_use_count = nullptr;

	}
}

template<typename T>
Smartptr<T>::Smartptr(Smartptr<T> const& oldptr)
{
	this->_use_count = oldptr._use_count;
	this->ptr = oldptr.ptr;
	++(*_use_count);
}

template<typename T>
Smartptr<T>& Smartptr<T>::operator=(Smartptr<T> const& oldptr)
{
	/*
	p=q,
	1.首先把q指向的对象的引用计数+1，因为p重新指向了q所指的对象
	p原来的对象的引用计数 减少1，如果减1后为0，释放掉p原来指向的内存
	然后将q指向的对象的引用计数加1，赋值给p


	这个就是c++ shared_ptr的原则
	以 r 所管理者替换被管理对象。若 *this 已占有对象且它是最后一个占有该对象的 shared_ptr 
	，且 r 与 *this 不相同，则通过占有的删除器销毁对象。
	
	*/
	++* (oldptr._use_count);
	if ((-- * (_use_count)) == 0) {
		delete ptr;
		ptr = nullptr;
		delete _use_count;
		_use_count = nullptr;
	}
	ptr = oldptr.ptr;
	*(_use_count) = *(oldptr._use_count);
	return *this;



}

template<typename T>
Smartptr<T>::~Smartptr()
{
	/*
	在析构函数中检测当前对象的引用计数 是不是只有正在结束生命周期的smartptr的引用
	如果是，就释放掉，否则还有其他的smartptr引用当前对象，就等待其他的smartptr对象
	在生命周期结束时候调用析构释放内存。但是引用计数还是--了
	
	*/
	if (--(*_use_count) == 0) {//
		delete this->ptr;
		this->ptr = nullptr;

		delete this->_use_count;
		this->_use_count = nullptr;
	}
}

template<typename T>
T Smartptr<T>::operator*()
{
	return *ptr;
}

template<typename T>
T* Smartptr<T>::operator->()
{
	return ptr;
}

template<typename T>
T* Smartptr<T>::operator+(int i)
{
	T* temp = ptr + i;
	return temp;
}

//template<typename T>
//int Smartptr<T>::operator-(Smartptr<T>& t1, Smartptr<T>& t2)
//{
//	return t1->ptr-t2->ptr;
//}






template<typename T>
int Smartptr<T>::use_count()
{
	return *(this->_use_count);
}

template<typename T>
T* Smartptr<T>::get()
{
	return this->ptr;
}













#endif

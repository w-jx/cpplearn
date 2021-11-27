#if 0
#include "wjxHeaders.h"

template<typename T> 
class Smartptr
{
public:
	Smartptr() ;//����һ���հ�����ָ��
	Smartptr(T&& arg);
	Smartptr(T* p); //Smartprt<int> p(new int(2))
	Smartptr(Smartptr<T> const& oldptr);//smartptr<int> q(p)
	Smartptr<T>& operator=(Smartptr<T> const& oldptr);//����=
	~Smartptr();
public:
	T operator*();//Ϊ�˰�����ָ�뵱����ָͨ�붨�������
	T* operator->();//����ȡ��Ա����
	T* operator+(int i);//����ָ�� ��һ������
	//int operator-(Smartptr<T> &t1, Smartptr<T> &t2);
	int use_count();
	T* get();

private:
	T* ptr;//�ײ�ָ��
	int* _use_count;//���浱ǰ���󱻶���ָ�����ü���
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
	catch (...)//���������쳣
	{//����ʧ�� �ͷ���ʵָ������ü������ڴ�
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
	catch (...)//���������쳣
	{//����ʧ�� �ͷ���ʵָ������ü������ڴ�
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
	1.���Ȱ�qָ��Ķ�������ü���+1����Ϊp����ָ����q��ָ�Ķ���
	pԭ���Ķ�������ü��� ����1�������1��Ϊ0���ͷŵ�pԭ��ָ����ڴ�
	Ȼ��qָ��Ķ�������ü�����1����ֵ��p


	�������c++ shared_ptr��ԭ��
	�� r ���������滻����������� *this ��ռ�ж������������һ��ռ�иö���� shared_ptr 
	���� r �� *this ����ͬ����ͨ��ռ�е�ɾ�������ٶ���
	
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
	�����������м�⵱ǰ��������ü��� �ǲ���ֻ�����ڽ����������ڵ�smartptr������
	����ǣ����ͷŵ���������������smartptr���õ�ǰ���󣬾͵ȴ�������smartptr����
	���������ڽ���ʱ����������ͷ��ڴ档�������ü�������--��
	
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

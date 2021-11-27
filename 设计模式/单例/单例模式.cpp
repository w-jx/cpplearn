#if 1
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define THREAD_DANGER_MODE false
#define LAZY_MAN_MODE false
#define HUNGRY_MAN_MODE true
using namespace std;

/*
class Teacher ����ǰд�ģ����̲߳���ȫ�ĵ���ģʽ

Ĭ�ϵĹ��캯�����������캯������ֵ���캯������Ϊ˽�е�

���ǵ������߳�ͬʱ���� getInstance ����������ͬʱ��⵽ instance �� NULL��
�����̻߳�ͬʱʵ�������󣬲����ϵ���ģʽ��Ҫ��

*/
class Teacher
{
public:
	Teacher()
	{
		cout << "hello,world\n";
	}
	~Teacher()
	{
		cout << "over\n";
	}
	inline static Teacher *get_instance()
	{
		if (m_instance == nullptr)
			m_instance = new Teacher;
		return m_instance;
	}

	void print()
	{
		cout << "1111\n";
	}

	inline static Teacher *m_instance = nullptr; //c++ 17
};

#if THREAD_DANGER_MODE
//�������ǰ��д��
class Singleton
{
private:
	static Singleton *instance;
	Singleton() {}
	Singleton(const Singleton &tmp) {}
	Singleton &operator=(const Singleton &tmp) {}

public:
	static Singleton *getInstance()
	{
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		return instance;
	}
};
Singleton *Singleton::instance = NULL;
#endif

//����ģʽ��ֱ����һ���õ����ʵ��ʱ��ȥʵ����
#if LAZY_MAN_MODE
class Singleton
{
private:
	static pthread_mutex_t mutex;
	static Singleton *instance;
	Singleton()
	{
		pthread_mutex_init(&mutex, NULL);
	}
	Singleton(const Singleton &tmp) {}
	Singleton &operator=(const Singleton &tmp) {}

public:
	static Singleton *getInstance()
	{
		pthread_mutex_lock(&mutex);
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		pthread_mutex_unlock(&mutex);
		return instance;
	}
};
Singleton *Singleton::instance = NULL;
pthread_mutex_t Singleton::mutex;
#endif

#if HUNGRY_MAN_MODE
class Singleton
{
private:
	static Singleton *instance;
	Singleton(const Singleton &temp) = default;
	Singleton &operator=(const Singleton &temp) = default;

protected:
	Singleton() {}

public:
	static Singleton *getInstance()
	{
		return instance;
	}
	void test()
	{
		cout << "test" << endl;
	}
};
Singleton *Singleton::instance = new Singleton();
#endif

class T
{
private:
	static T *instance;
	T() = default;
	T(const T &) = default;
	T &operator=(const T &) = default;
public:
	static T *get_instance()
	{
		return instance;
	}
	void test()
	{
		cout << "test" << endl;
	}
};
T *T::instance = new T();

void test01()
{
	Teacher::get_instance()->print(); //����:�ȹ��캯��,��ִ��print()

	//delete Teacher::get_instance(); ���û��,û������
	Teacher::get_instance()->~Teacher(); //����������
}

void test02()
{
	T::get_instance()->test();
}
int main(void)
{
	//test01();
	test02();
	return 0;
}
#endif
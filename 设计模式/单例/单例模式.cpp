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
class Teacher 是以前写的，是线程不安全的单例模式

默认的构造函数、拷贝构造函数、赋值构造函数声明为私有的

考虑当两个线程同时调用 getInstance 方法，并且同时检测到 instance 是 NULL，
两个线程会同时实例化对象，不符合单例模式的要求。

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
//这个是以前的写法
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

//懒汉模式：直到第一次用到类的实例时才去实例化
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
	Teacher::get_instance()->print(); //结论:先构造函数,在执行print()

	//delete Teacher::get_instance(); 这个没有,没有析构
	Teacher::get_instance()->~Teacher(); //主动析构吧
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
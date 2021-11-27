#if true
#include "../wjxHeaders.h"
#define FUNCTION_TEMPLATE true
#define CLASS_TEMPLATE true
#define TYPE_TRAITS true

//函数模板
template<class T>
T add(T a, T b)	{ return a + b;}

//最简单的类模板
template<class T>
class A
{
public:
	explicit A(T val) : t(val) { }
	T add(T x) { return t + x; }	
private:
	T t;
};

/*
类模板的和函数模板都必须定义在.h头文件中，不能分离

1.链接的时候，需要实例化模板，这时候就需要找模板的具体实现了。假设在main函数中调用了一个模板函数，这时候就需要去实例化该类型的模板。
注意main函数里面只包含了.h文件，也就是只有模板的声明，没有具体实现。就会报错。
2.而模板的实现.cpp里面，虽然有模板的具体实现，但是没有谁在该.cpp里面使用一个模板函数，就不会生成一个具体化的实例。

模板的实例化类型确定是在编译期间


*/
#if FUNCTION_TEMPLATE
//1.函数模板只能全特化，不能偏特化，偏特化就是函数重载了
template<>
double add(double a,double b)
{
    return a+b+1;
}
//函数模板的重载，接收参数为指针
template<typename T1>
T1 add(T1* a,T1* b) {
    return *a+*b;
}

//函数模板的全特化
void test01()
{
    cout<<add(1,2)<<endl;
    cout<<add(1.0,2.0)<<endl;

    auto a = make_shared<int>(10);
    auto b = make_shared<int>(20);

    cout<<add(a.get(),b.get())<<endl;;//重载

}
#endif 

#if CLASS_TEMPLATE
//类模板的全特化
template< >     // 注意语法
class A<char*>       // 一个全特化的模板类A
{                    // 当用char*类型来实例化类模板A时，将会优先调用这个全特化实例
public:
	explicit A(char* val) : t(val) { }
	char* add(char* a, char* b) { return strcat(a, b); }
private:
	char* t;
};
//类模板的偏特化 第一种形式
template<class T1, class T2>      // 普通版本，有两个模板参数
class B 
{

};

template<class T2>// 偏特化版本，指定其中一个参数，即指定了部分类型
class B<int , T2> {  };// 当实例化时的第一个参数为int 则会优先调用这个版本


//类模板的偏特化 第二种形式
template<class T>
class C //普通版本，1个模板参数
{

};

template<class T> 
class C<T*> //只接受指针的偏特化
{

};
template<class T> 
class C<T&> //只接受引用的偏特化
{   

};

//类模板的偏特化 第三种形式
template<class T>
class D{}; //普通版本，1个模板参数
template<class T>
class D<vector<T> >{};//偏特化版本，接受vector<T> 类型

#endif

#if TYPE_TRAITS

//用这个 来自定义自己的类型，比如说数组，int，string 型这样的
template<typename T>
class MyVal
{
    MyVal(T _val):val(_val){}
private:
    T val;
};

template<>
class MyVal<int>
{
    
    
};

#endif


int main() {

	test01();
	return 0;
}

#endif
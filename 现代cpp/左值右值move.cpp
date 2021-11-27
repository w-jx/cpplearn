#if 1
#include <iostream>
#include <vector>
using namespace std;


/*

所以很多时候，自己写的一个函数
例如
void func(int& input)
当调用func(5)无法通过编译，因为无法将右值绑定到一个左值引用上
但是我们可以通过添加const 解决
void func(const int& input)
这样我们可以func(a),func(5)解决，但是面对要修改变量值的场景，无法兼顾

*/



//什么是左值右值
void test01()
{
	//左值可以取地址，位于等号左边，右值不能取地址，位于等号右边
	//a位于等号左边，可以利用&取地址，所以a是左值
	//5位于等号右边，5不能利用&取地址，所以5是个右值
	int a = 5;

	//有地址的变量就是左值，没有地址的字面值、临时值就是右值。
}
//左值引用
void test02()
{
	//能指向左值，不能指向右值的就是左值引用
	int a = 5;
	int& ref_a = a; // 左值引用指向左值，编译通过
	//int& ref_a = 5; // 左值引用指向了右值，会编译失败
	//引用是变量的别名，由于右值没有地址，没法被修改，所以左值引用无法指向右值。
	//const左值引用是可以指向右值的
	 int const& ref_b = 5;  // 编译通过
	//const左值引用不会修改指向值，因此可以指向右值
	/*
		void push_back (const value_type& val);
		如果没有const，vec.push_back(5)这样的代码就无法编译通过了。
	*/
}
//右值引用
void test03()
{
	//右值引用的标志是&&，可以指向右值，不能指向左值
	int&& ref_a_right = 5; // ok

	int a = 5;
	//int&& ref_a_left = a; // 编译不过，右值引用不可以指向左值

	ref_a_right = 6; // 右值引用的用途：可以修改右值

}
//右值引用    ----指向左值
void test04()
{
	int a = 5; // a是个左值
	int& ref_a_left = a; // 左值引用指向左值
	int&& ref_a_right = std::move(a); // 通过std::move将左值转化为右值，可以被右值引用指向

	cout << ref_a_right; // 打印结果：5
	/*
	std::move移动不了什么，唯一的功能是把左值强制转化为右值，让右值引用可以指向左值。
	其实现等同于一个类型转换：static_cast<T&&>(lvalue)。
	*/
}


//右值引用
void changeNumRightRef(int&& num)
{
	num += 1;
}
//万能引用
template<class T>
void changeNumAllRef(T&& num)
{
	num += 1;
}
void changeNumConstRightRef(const int&& num) 
{

}
void changeNumLeftRef(int& num) 
{

}
//右值引用测试
void test05()
{
	int a = 10;
	changeNumRightRef(std::move(a));//changeNum(a)无法通过编译
	cout << a << endl;

	changeNumAllRef(a);//万能引用，可以通过编译
	changeNumAllRef(std::move(a));//左值右值都可以
	cout << a << endl;
}
//std::forward 可以类型转换左值或者右值
void test06()
{
	//changeNum只支持右值参数
	int a = 10;
	//changeNum(a);//无法通过
	changeNumRightRef(std::move(a));//右值可以通过

	changeNumRightRef(std::forward<int&&>(a));//T为右值引用，转换为右值，可以通过
	//changeNum(std::forward<int&>(a));//T为左值引用，转换为左值，无法通过
	changeNumAllRef(std::forward<int&>(a));//changeNum2支持左右值
	changeNumRightRef(std::forward<int>(a));//通过，这个是右值？
	changeNumRightRef(std::forward<int>(10));//通过，这个是右值？？
	//changeNum(std::forward<int &>(1));//无法通过，左值
}
void test07()
{
	int a = 10;
	//无法将右值引用绑定到左值，即便加const 也没有用
	//changeNum3(a);
	//changeNumLeftRef(10);//无法编译通过
	changeNumAllRef(a);
	changeNumAllRef(10);
}


int returnVal()
{
	return 10;
}

void test08()
{

	int && a = returnVal();
	//int &b = returnVal();//非常量引用的初始值必须是左值。
	const int & c = returnVal();
}


class HugeMem{

public:
	HugeMem(int size):sz(size>0?size:1){arr = new int [sz];}
	~HugeMem(){
		delete[] arr;
	}
	HugeMem(HugeMem && hm):sz(hm.sz),arr(hm.arr){
		hm.arr = nullptr;
	}
private:
	int *arr;
	int sz;
};
class Moveable{
public:
	Moveable():i(new int(3)),h(1024){}
	Moveable( Moveable &&m):i(m.i),h(move(m.h)){
		m.i = nullptr;
		cout<<"called\n";
	}
private:
	int *i;
	HugeMem h;
};
Moveable GetMoveable()
{
	Moveable temp = Moveable();
	return temp;
}
//移动构造
void test09()
{
	GetMoveable();
}
int main(void)
{
	//test05();//右值引用测试
	//test04();
	//test08();
test09();
	return 0;
}
#endif
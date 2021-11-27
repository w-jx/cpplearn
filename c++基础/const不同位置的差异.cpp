#if 0
#include "wjxHeaders.h"

typedef int INT;
typedef int* INTP;

typedef INTP const CINTP;//int * const  指向整形的常指针
//类型定义 是定义的  别名，不是新类型
typedef int* const CINTP2;//等价的，指向整形的常指针  


//如果我们把const 放在前面，等价原则就不适用了
typedef const INTP CINTP3;// const int * 指向常整形的指针 
typedef const int* CINTP4;//上下不等价了

/*
上面说这么多，就是为了证明
	const int a1 = 10;//常整形 不能修改值
	int const a2 = 10; //这两个等价

	但是在typedef 中如果把const 放在后面是等价的，CINTP，CINTP2
	放在前面 CINTP3，CINTP4不等价


	所以我们建议把const 放在类型 后面，同样的原则也适用volatile

*/

void test01()
{

	const int a1 = 10;//常整形 不能修改值
	int const a2 = 10; //这两个等价,但是更推荐写int const
	//a1 = 11;//不通过，常整形无法修改值


	int a = 10;
	int a3 = 11;
	int* a_pointer = &a;
	int* a3_pointer = &a3;
	*a_pointer = 11;//通过
	a_pointer = &a3;//通过，可以修改指向
	//a_pointer = &a1;//不通过，不能将int const * 的值分配到int * 的实体
	cout << "after a_pointer ,a=" << a << endl;

//1.
	int const* b = &a;    //指针 指向的是常整形  
	//*b = 11; //非法，常整形无法修改值 (表达式必须是可修改的左值）
	b = &a2; //通过，指针不是常指针，可以修改指向
//2.
	int const* const c = &a;//常指针 指向的是常整形
	//c = &a3;//不通过，常指针，无法修改指向
	//*c = 11;//不通过，无法修改值，因为是常整型


//3.
	int* const d = &a;// 常指针，指向的是整形
	//d = &a3;//不通过，因为是常指针
	*d = 120;//通过，因为指向的是整形
	cout << "after d ,a=" << a << endl;

//4.
	int* e_pointer = &a;
	
	int* const* e = &e_pointer;//对 整形 的 常指针 的指针 
	//本质上是指针的指针，所以是对指针取地址
	**e = 140;//整形，可以修改
	cout << "after e ,a=" << a << endl;
	e = &a3_pointer;//指针，可以修改指向
	//*e = &a3; //不通过，常指针，无法修改指向
}
void test02()
{
	INT a = 10;
	INT a1 = 20;
	INTP b = &a;
	cout << "a=" <<a<< ",*b=" << *b << endl;

	CINTP c = &a;
	*c = 20;//通过，指向的是整形
	//c = b;//不通过，常指针

	CINTP3 d = &a;//理论上我们认为是const int * ,也就是指向常整形的指针
	*d = 20;//通过
	//d = &a1;//不通过，所以实际上是 指向整形的常指针
	
	CINTP4 e = &a;//const int *   指向常整形的指针
	//*e = 10;//不通过。指向常整形
	e = &a1;//通过，指针


}
int main()
{
	//test01();//const 不同位置的差异
	test02();
	system("pause");
	return 0;
}


#endif
#if 0
#include <iostream>
using namespace std;

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}
//shared_ptr
void test01()//
{
	//1.shared_ptr 的声明
	//auto pointer = std::make_shared<int>(10);
	//foo(pointer);
	//std::cout << *pointer << std::endl;


	/*
	shared_ptr<T> operator=(shared_ptr<T> & r)
		以 r 所管理者替换被管理对象。

若 *this 已占有对象且它是最后一个占有该对象的 shared_ptr ，且 r 与 *this 不相同，则通过占有的删除器销毁对象。
	*/

	//2.其他技术

	auto pointer = std::make_shared<int>(10);
	auto pointer2 = pointer; // 引用计数+1
	auto pointer3 = pointer; //引用计数+1
	auto pointer4 = std::shared_ptr(pointer);


	int* p = pointer.get(); // 这样不会增加引用计数
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3
	

	pointer2.reset();
	std::cout << "reset pointer2:" << std::endl;
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
	pointer3.reset();
	std::cout << "reset pointer3:" << std::endl;
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset


	
}
//shared ptr实现动态数组
void test02()//
{
	//auto list = { 1,3,4,5,6,7,8,8 ,10,2 };
	auto sp3 = std::make_shared<int[]>(10,1024);//c++ 20支持,数组初始化10个1024


	for (int i = 0; i < 10; i++) {
		std::cout << sp3[i] << " ";
	}
	





}
//unique_ptr 独占智能指针
void test03()//
{
	auto up2 = std::make_unique<int >(10);

	//auto p3 = up2;//非法,因为unique_ptr是独占的

	cout << *up2 << endl;

	auto p = up2.get();

	//auto up3 = std::make_unique<int[]>(10);//不合法,不能直接初始化
	auto up3 = std::make_unique<int[]>(10);// 默认初始化0，注释下面的语句可得
	/*for (int i = 0; i < 10; i++) {
		up3[i] = i;
	}*/
	for (int i = 0; i < 10; i++) {
		cout << "up3[" << i << "]=" << up3[i] << endl;
	}

}
//weak_ptr
void test04()
{
	//std::weak_ptr 是一种智能指针，
	//它对被 std::shared_ptr 管理的对象存在非拥有性（「弱」）引用。
	//在访问所引用的对象前必须先转换为 std::shared_ptr。
	std::weak_ptr<int> w_ptr;//创建新的对象
	auto pointer = std::make_shared<int>(10);
	w_ptr = std::weak_ptr<int>(pointer);

	std::weak_ptr<int> w_ptr2(pointer);//直接构造函数就行
	

	//use_count() 返回共享被管理对象所有权的 shared_ptr 实例数量
	cout << "w_ptr2.use_count=" << w_ptr.use_count() << endl;//1
	auto pointer2 = pointer;
	auto pointer3 = pointer;
	cout << "w_ptr2.use_count=" << w_ptr.use_count() << endl;//3

	auto pointer4 = w_ptr;
	cout << "w_ptr2.use_count=" << w_ptr.use_count() << endl;//3

	cout << "*pointer=" << *w_ptr.lock() << endl;

	pointer.reset();
	cout << "after reser,w_ptr2.use_count=" << w_ptr.use_count() << endl;//2
}

void test05()
{
	auto p = make_shared<int>(13);
	auto  p_ptr = p.get();
	cout << "use_count=" << p.use_count() << endl;//1


	{
		//auto p1 = p;
		//shared_ptr<int> p1(p_ptr);//相当于用指针初始化，肯定不会增加引用计数
		shared_ptr<int> p1(p);//拷贝构造
		cout << "use_count=" << p.use_count() << endl;//auto p1=q 时候是2，shared_ptr<int> p1(p_ptr)时候是1
		(*p1)++;
	}
	int ret = (*p)++;
	cout << "ret=" << ret << endl;
}
int main(void)
{

	//test01();//shared_prt
	//test02();//shared_ptr生成数组
	//test03();//unque_ptr使用
	test04();//weak_ptr的使用
	//test05();
	system("pause");
	return 0;

}
#endif
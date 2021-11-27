
#include <iostream>
#include <vector>
#include <functional>
using namespace std;



//函数对象类
struct divide 
{
    int operator()(int denominator, int divisor) 
    {
        return denominator / divisor;
    }
};
// 普通函数
int add(int a, int b) { return a + b; }

// lambda表达式   
//注意：【=】 non-local lambda expression cannot have a capture-default错误
auto mod = [](int a, int b) {return a % b; };

//仿函数，普通函数，lambda表达式都是 int(int,int)形式
//std::function 将类型保存下来

std::function<int(int, int)> func1 = divide();
std::function<int(int, int)> func2 = add;
std::function<int(int, int)> func3 = mod;
auto func4 = add;//显然可以用auto 自动类型推导

void test01()//测试三种函数测试
{
    cout<<"func1="<<func1(10, 2)<<endl;
    cout << "func2=" << func2(10, 2) << endl;
    cout << "func3=" << func3(10, 2) << endl;
}
/*
容纳除了类成员函数指针之外的所有可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。
std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用。它比普通函数指针更加的灵活和便利。
*/

/*下面是std::bind
std::bind将可调用对象与其参数一起进行绑定，绑定后的结果可以使用std::function保存。std::bind主要有以下两个作用：

将可调用对象和其参数绑定成一个仿函数；
只绑定部分参数，减少可调用对象传入的参数。

*/
double my_divide(double x, double y) { return x / y; }
void test02()//bind绑定 普通函数
{
    auto fn_half = std::bind(my_divide, std::placeholders::_1, 1);
    auto fn_half2 = std::bind(my_divide, 100, 25);
    auto fn_half3 = std::bind(my_divide, 100, 25);
    std::cout << fn_half(10) << '\n';
    std::cout << fn_half2() << '\n';
}
struct Foo {
    void print_sum(int n1, int n2)
    {
        cout<<"n1:"<<n1<<",n2:"<<n2<<endl;
        std::cout << n1 + n2 << '\n';
    }
    int data = 10;
};
void test03()//bind 绑定 成员函数
{
    Foo foo;
    //参数1必须加&，因为编译器不会自动将对象成员函数转化程函数指针
    //参数2：使用对象成员函数指针，必须要知道该指针属于哪个对象

    auto f = std::bind(&Foo::print_sum, &foo, 95, std::placeholders::_1);
    f(5);//预设了第一个参数是95


    auto f2 = std::bind(&Foo::print_sum,&foo,std::placeholders::_1,std::placeholders::_2);
    f2(100,200);

    auto f3 = std::bind(&Foo::print_sum,&foo,std::placeholders::_2,std::placeholders::_1);
    f3(40,20);//改变了参数顺序

    
    auto f4 = std::bind(&Foo::print_sum, &foo,std::placeholders::_1,101);
    f4(10);

   // auto f5 = std::bind(&Foo::print_sum, &foo,std::placeholders::_2,101);
    //f5(20);//占位符的顺序必须从1开始，不能任意指定
 
}


//类内 用bind
class Base{
    public:
        Base()=default;
        void test() {
            auto func = Callable;
            
        }
        void Callable() {
            cout<<"hello,world";
        }
    private:
        int p1;
        int p2;
};


int main(void)
{
   // test01();//functional 三种函数测试
    //test02();//bind  测试 

    test03();
	
	return 0;
}

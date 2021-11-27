#include "../wjxHeaders.h"
#define HIDE_PARAMETER 1
#define NON_TEMPLATE_PRIORITY 1 //非模板优先
#define Type_Transfer 1 //类型转换





//<<template>>附录B

//先类型演绎->重载解析

template<typename T>
class Mystring{
    public:
        Mystring()=default;
        Mystring(T const *){

        }
};

template <typename T>
Mystring<T> truncate(Mystring<T>const & p1,int p2)
{
    return Mystring(p1);
}
void test01()
{
    Mystring <char> str1,str2;
    str1 = truncate<char>("hello,world",5);
    //str2 = truncate("hello,world",5);//错误,没有与参数模板匹配的函数
}

//成员函数的 隐含实参
#if HIDE_PARAMETER
//在成员函数内部,有一个隐含参数 *this
//对于non_const函数:Myclass &
//对于const 函数:Myclass const &

#endif


#if NON_TEMPLATE_PRIORITY
template <typename T> int f(T);
void f(int);

int TEST_NON_TEMPLATE_PRIORITY()
{
   //return f(7); //选择了2,但是2没有返回值
   return f<int>(7);
}

#endif 


#if Type_Transfer
class Base {

public:

operator short() const;

};

class Derived : public Base {

};

void count(int);

void process(Derived const& object)

{

count(object);////匹配：应用了用户自定义的转型

}
#endif
int main()
{

}
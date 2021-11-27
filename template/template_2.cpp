#include "../wjxHeaders.h"
//<<templte>> 第2章

//返回类型 演绎

template<typename T1,typename T2,typename Rt>
inline Rt max(T1 const &a,T2 const & b) {
    return a<b?b:a;
}
void test01()
{
    auto res = max<int,int,double> (10,20);
    cout<<"res:"<<res<<endl;

    auto res1 = max<double>(30,40);//前两个调用实参演绎,double指定返回类型
    cout<<"res1:"<<res1<<endl;
}

int main()
{
    test01();
}
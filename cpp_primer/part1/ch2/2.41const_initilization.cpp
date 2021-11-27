#include <iostream>
using namespace std;




int main()
{
    double val = 3.14;
    const int &r1 = val;//合法

    //int &r2 = val;//非法


    //const 引用并没有 限制 被引用/绑定的对象,可以引用非const 对象
    int var = 1;
    int &var_non_const = var;
    const int &var_const = var;
    //var_const = 2;//显然错误
    //值都是1
    cout<<"var_non_const:"<<var_non_const<<",var_const:"<<var_const<<endl;   

    var_non_const = 20;//如果这边改变了var的值
    cout<<"var_non_const:"<<var_non_const<<",var:"<<var<<endl; 

    //问题:var_const 的值是否被改变了,结论:改变了
    cout<<"var_const:"<<var_const<<endl;

}
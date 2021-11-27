#include <iostream>
using namespace std;

int compare(int a,int b) {
    return a>b?a:b;
}z


using F = int(int,int );//f是函数,非指针
using PF = int (*)(int,int);

PF funcRet() {
    return compare;
}

// F funcRet2(){

// }//错误,不允许使用返回函数的函数
int main()
{
    cout<<funcRet()(20,10)<<endl;
}
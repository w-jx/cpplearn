#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;
//return str[0:idx];
string SubStr(const string &str,int idx) {
    return str.substr(0,idx);
}

int main()
{
    string str = "happy";
    auto newstr = SubStr(str,3);
    cout<<newstr<<endl;
    //bind 作用1:更换参数顺序
    auto SubStr2 = bind(SubStr,std::placeholders::_2,std::placeholders::_1);
    auto newstr2  =SubStr2(2,str);
    cout<<newstr<<endl;
    //bind 作用2:函数适配器,通过一个可调用对象,生成另外一个可调用对象



}
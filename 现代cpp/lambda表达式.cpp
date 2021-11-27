#if true
#include "wjxHeaders.h"

/*
[ capture ] ( params ) opt -> ret { body; };
[]->no capture
[&] -> capture all variables with reference format
[=] -> capture all variables with value format
[=,&foo]->capture all variables with value format,and capture variable 'foo' with reference format
[foo]->capture variable foo with value
[this]-> capture this ptr in a class 

可以认定为 仿函数

std::function <int(int)> f1 = [](int a){return a;};
std::function <int<int>> f2 = std::bind([](int a){return a;},123);

*/
void test01()
{
    std::function <int(int)> f2 = std::bind([](int a){return a;},std::placeholders::_1);//默认值
    auto ret = f2(10);
    cout<<"ret:"<<ret<<endl;
}

int main() {

	test01();
	return 0;
}

#endif
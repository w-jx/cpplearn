
#include <iostream>
#include <vector>
using namespace std;

namespace ns1
{
	int a=1;
	struct myaddr
	{
		int b;
		int c;
	};
}
namespace ns2
{
	int a = 1;
	struct myaddr
	{
		int b;
		int c;
	};
}
using namespace ns1;
using namespace ns2;


//现在有一个疑问，namespace里面的值可以被改动嘛？
//结论：可以更改
void test01()
{
	cout<<ns2::a<<endl;//显然输出1
	ns2::a =10; 
	cout<<"after changed:"<<ns2::a<<endl;//

}
int main(void)
{
	test01();

	return 0;
}

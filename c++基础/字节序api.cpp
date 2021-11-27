#if 0

#include <WS2tcpip.h> //inet_pton
#include <iostream>
#include "winsock2.h" //引用头文件
#pragma comment (lib,"ws2_32.lib") //链接库文件

using namespace std;

void test01()
{
	int i ;
	int ret = inet_pton(AF_INET, "127.0.0.1", (void *)i);
	cout << "dst=" <<i << endl;


}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
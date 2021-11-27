#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include < numeric >

using namespace std;
/*
leecodeÌâÄ¿½éÉÜ:


*/
void test01()
{
	vector<int> v{ 1,2,3,4,5 };
	int sum = std::accumulate(v.cbegin(), v.cend(),0);
	cout << "sum=" << sum << endl;


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
#if 0
#include "wjxHeaders.h"


template <typename T1, typename T2>
inline T1 max(T1 const& a, T2 const& b)
{
	return a < b ? b : a;

}
//这个模板的缺点
void test01()
{
	cout << max(42, 66.66) << endl;;//66
	cout << max(66.66,42) << endl;;//66.66
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
#if 1
#include "wjxHeaders.h"

/* ���ۣ�
1.sort Ҳ���Զ� string ʹ��

*/

template<typename Item>
bool compare(Item a,Item b){
	return a>b;
}
void test01()
{
	string str = "avdeq";
	sort(str.begin(), str.end(),std::greater<char>());
	cout << str << endl;;

	vector<int> nums{1,5,2,7,4};
	//sort(nums.begin(),nums.end(),compare);
}
int main()
{
	test01();
	return 0;
}
#endif
#if 0
#include "wjxHeaders.h"
using namespace std;
static int ret;


void for_each_hash(unordered_map<string,int> &hash)
{
	unordered_map<string, int>::iterator it = hash.begin();
	while (it != hash.end()) {
		cout << it->first << "," << it->second << endl;
		it++;
	}
}
void for_each_hash2(unordered_map<string, int>& hash)
{
	for (auto iter : hash) {
		cout << iter.first << "," << iter.second << endl;
	}
}
void test01()
{
	unordered_map<string, int> hashtable;
	//cout << hashtable.empty() << endl;
	//hashtable.insert(make_pair("hello", 123));
	auto iter = hashtable.begin();
	//cout << iter->first << endl;
	if (iter == hashtable.end())
		cout << "empty" << endl;

	hashtable.insert(make_pair("111", 111));
	hashtable.insert(make_pair("222", 222));
	hashtable.insert(make_pair("333", 333));
	hashtable["333"] = 3;
	for_each_hash(hashtable);
	cout << "for_each_hash2" << endl;
	for_each_hash2(hashtable);
	//hashtable.erase("111");
	//cout << "after erase \n";
	//for_each_hash(hashtable);
}
//哈希映射的遍历问题，为什么会出现顺序异常的现象
void test02()
{
	unordered_map<string, int> hashtable;
	hashtable.insert(make_pair("ab", 1));
	hashtable.insert(make_pair("cd", 2));
	hashtable.insert(make_pair("ef", 3));
	[=]() {
		for (auto iter : hashtable)
			cout << iter.first << " ";
		cout << endl;
	}();
	hashtable["cd"]++;
	[=]() {
		for (auto iter : hashtable)
			cout << iter.first << " ";
		cout << endl;
	}();
}
int main(void)
{
	///test01();
	//test02();//因为unordered_map是哈希表，不是有序的，只有map红黑树才是有序的
	

	system("pause");
	return 0;
}
#endif
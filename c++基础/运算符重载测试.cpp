#if 0
#include <iostream>
#include <vector>
#define VNAME(value) #value   
using namespace std;



void printVector(vector<int> v,string s)
{
	cout << s << ":";
	for (auto iter : v)
	{
		cout << iter << " ";
	}
	cout << endl;
}
class MyAdd
{
public:
	MyAdd(int a) :m_Num(a) {}
	int operator-(int v1)
	{
		this->m_Num += v1;
		return this->m_Num;
	}
	int m_Num;
};

void test01()//
{
	MyAdd myadd(5);
	cout << (myadd - 7) << endl;;

}

void test02()//
{
	vector<int>v1;
	vector<int>v2;

	v1.push_back(1);
	v1.push_back(2);

	printVector(v1, VNAME(v1));


}


class Teacher
{
public:
	Teacher() {};
	int id;
	string name;
};

/*
首先，下面的函数不能通过编译，因为
int a=10;
cout<<a；是编译器已经提供的用法，提示已经声明了，所以，重载<<要用在自定义数据类型
才有意义！
*/
//void operator<<(ostream& out, int& t) //---->错误，因为已经有这样类似的函数原型了
//{
//	out << t << "hello";
//}
//void operator<<(ostream& out, Teacher& t)
//{
//	out << "id=" << t.id << ",name=" << t.name ;
//	
//}
ostream& operator<<(ostream& out, Teacher& t)
{
	out << "id=" << t.id << ",name=" << t.name;
	return out;
}
void test03()
{
	Teacher t;
	t.id = 10;
	t.name = "www";

	cout << t<<",jjjjj\n";
}

int main(void)
{

	//test01();//
	//test02();//
	test03();//
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
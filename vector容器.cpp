#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val) {
	std::cout << val << std::endl;;
}

class Teacher
{
public:
	Teacher(int age, string name)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	int getAge() 
	{
		return this->m_Age;
	}
	string getName()
	{
		return this->m_Name;
	}
	void setName(string &name)
	{
		this->m_Name = name;
	}
	void setAge(int& age)
	{
		this->m_Age = age;
	}

private:
	int m_Age;
	string m_Name;

};

//------------------------------------------
//����
void test01()
{
	vector<int>v;
	v.push_back(19);
	v.push_back(20);
	v.push_back(21);
	v.push_back(22);


	vector<int>::iterator vBegin = v.begin();//��ʼ������
	vector<int>::iterator vEnd = v.end();//��ʼ������
	//while (vBegin != vEnd) {  //��ʽ1
	//	std::cout << *vBegin << std::endl;
	//	vBegin++;
	//}

	//��ʽ2::forѭ��
	
	//��ʽ3 for_each��׼�㷨
	//for_each(v.begin(), v.end(), myPrint);//

	//������������auto�ؼ���
	//for (auto a = v.begin(); a != v.end(); a++) {
	//	std::cout << *a << std::endl;
	//}

}
//vector����Զ���ṹ����
void test02()//vector����Զ���ṹ����
{
	vector<Teacher>vTeacher;

	Teacher t1(23, "wjx");
	Teacher t2(21, "zj");
	vTeacher.push_back(t1);
	vTeacher.push_back(t2);


	for (auto it = vTeacher.begin(); it != vTeacher.end(); it++)
	{
		std::cout << "name= " << it->getName() << ",age=" << it->getAge() << " ";

	}
	std::cout << std::endl;


}
//vector����Ƕ��
void test03()//
{
	vector<int> v1;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i);
	}
	vector<int>v2;
	for (int i = 4; i < 8; i++) {
		v2.push_back(i);
	}
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);

	for (auto it = v.begin(); it != v.end(); it++) {
		
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}

void test04()//
{

}

void test05()//
{

}

void test06()//
{

}



int main(void)
{

	//test01();//����
	//test02();////vector����Զ���ṹ����
	test03();//vectorǶ��
	//test04();//
	//test05();//
	//test06();//

	system("pause");
	return 0;

}
#endif
#if 0
#include "wjxHeaders.h"

//�������������	++

//�Զ�������
class MyInteger
{
	friend	ostream& operator<<(ostream& cout, MyInteger myint);
	//����<<�����
public:
	MyInteger()
	{
		M_num = 0;
	}
	MyInteger(int i):M_num(i){}
	//����++�������ǰ��
	MyInteger& operator++()//������صĲ������ã���ô���صľ���һ���µĶ����൱�ڿ���
	{						//����ȷ��һֱ�Ƕ�һ���������
		M_num++;
		return *this;//��������
	}
	//����++�����������
	MyInteger operator++(int)//int����ռλ������������������ǰ�úͺ��õ���
	{							//���õ���һ�����ص�ֵ���������ã�����������ã����Ǹ��ֲ���������ᱻ�ͷ�
								//�ٷ��ؾ��ǷǷ�����
		//�ȼ�¼һ�µ�ʱ�Ľ��
		MyInteger	temp = *this;
		//�����
		M_num++;
		//��󽲼�¼�Ľ������
		return temp;
	}
private:
	int M_num;
};
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.M_num;
	return cout;
}
void test01()//ǰ��++
{
	MyInteger myint=4;
	cout << ++myint << endl;
}
void test02()//����++
{
	MyInteger myint=10;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	//test01();//ǰ��++
	test02();//����++
	system("pause");
	return 0;
}
#endif
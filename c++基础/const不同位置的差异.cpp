#if 0
#include "wjxHeaders.h"

typedef int INT;
typedef int* INTP;

typedef INTP const CINTP;//int * const  ָ�����εĳ�ָ��
//���Ͷ��� �Ƕ����  ����������������
typedef int* const CINTP2;//�ȼ۵ģ�ָ�����εĳ�ָ��  


//������ǰ�const ����ǰ�棬�ȼ�ԭ��Ͳ�������
typedef const INTP CINTP3;// const int * ָ�����ε�ָ�� 
typedef const int* CINTP4;//���²��ȼ���

/*
����˵��ô�࣬����Ϊ��֤��
	const int a1 = 10;//������ �����޸�ֵ
	int const a2 = 10; //�������ȼ�

	������typedef �������const ���ں����ǵȼ۵ģ�CINTP��CINTP2
	����ǰ�� CINTP3��CINTP4���ȼ�


	�������ǽ����const �������� ���棬ͬ����ԭ��Ҳ����volatile

*/

void test01()
{

	const int a1 = 10;//������ �����޸�ֵ
	int const a2 = 10; //�������ȼ�,���Ǹ��Ƽ�дint const
	//a1 = 11;//��ͨ�����������޷��޸�ֵ


	int a = 10;
	int a3 = 11;
	int* a_pointer = &a;
	int* a3_pointer = &a3;
	*a_pointer = 11;//ͨ��
	a_pointer = &a3;//ͨ���������޸�ָ��
	//a_pointer = &a1;//��ͨ�������ܽ�int const * ��ֵ���䵽int * ��ʵ��
	cout << "after a_pointer ,a=" << a << endl;

//1.
	int const* b = &a;    //ָ�� ָ����ǳ�����  
	//*b = 11; //�Ƿ����������޷��޸�ֵ (���ʽ�����ǿ��޸ĵ���ֵ��
	b = &a2; //ͨ����ָ�벻�ǳ�ָ�룬�����޸�ָ��
//2.
	int const* const c = &a;//��ָ�� ָ����ǳ�����
	//c = &a3;//��ͨ������ָ�룬�޷��޸�ָ��
	//*c = 11;//��ͨ�����޷��޸�ֵ����Ϊ�ǳ�����


//3.
	int* const d = &a;// ��ָ�룬ָ���������
	//d = &a3;//��ͨ������Ϊ�ǳ�ָ��
	*d = 120;//ͨ������Ϊָ���������
	cout << "after d ,a=" << a << endl;

//4.
	int* e_pointer = &a;
	
	int* const* e = &e_pointer;//�� ���� �� ��ָ�� ��ָ�� 
	//��������ָ���ָ�룬�����Ƕ�ָ��ȡ��ַ
	**e = 140;//���Σ������޸�
	cout << "after e ,a=" << a << endl;
	e = &a3_pointer;//ָ�룬�����޸�ָ��
	//*e = &a3; //��ͨ������ָ�룬�޷��޸�ָ��
}
void test02()
{
	INT a = 10;
	INT a1 = 20;
	INTP b = &a;
	cout << "a=" <<a<< ",*b=" << *b << endl;

	CINTP c = &a;
	*c = 20;//ͨ����ָ���������
	//c = b;//��ͨ������ָ��

	CINTP3 d = &a;//������������Ϊ��const int * ,Ҳ����ָ�����ε�ָ��
	*d = 20;//ͨ��
	//d = &a1;//��ͨ��������ʵ������ ָ�����εĳ�ָ��
	
	CINTP4 e = &a;//const int *   ָ�����ε�ָ��
	//*e = 10;//��ͨ����ָ������
	e = &a1;//ͨ����ָ��


}
int main()
{
	//test01();//const ��ͬλ�õĲ���
	test02();
	system("pause");
	return 0;
}


#endif
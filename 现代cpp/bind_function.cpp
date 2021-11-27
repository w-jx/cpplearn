
#include <iostream>
#include <vector>
#include <functional>
using namespace std;



//����������
struct divide 
{
    int operator()(int denominator, int divisor) 
    {
        return denominator / divisor;
    }
};
// ��ͨ����
int add(int a, int b) { return a + b; }

// lambda���ʽ   
//ע�⣺��=�� non-local lambda expression cannot have a capture-default����
auto mod = [](int a, int b) {return a % b; };

//�º�������ͨ������lambda���ʽ���� int(int,int)��ʽ
//std::function �����ͱ�������

std::function<int(int, int)> func1 = divide();
std::function<int(int, int)> func2 = add;
std::function<int(int, int)> func3 = mod;
auto func4 = add;//��Ȼ������auto �Զ������Ƶ�

void test01()//�������ֺ�������
{
    cout<<"func1="<<func1(10, 2)<<endl;
    cout << "func2=" << func2(10, 2) << endl;
    cout << "func3=" << func3(10, 2) << endl;
}
/*
���ɳ������Ա����ָ��֮������пɵ��ö�����������ͳһ�ķ�ʽ���������������󡢺���ָ�룬����������ӳ����ǵ�ִ�С�
std::function����ȡ������ָ������ã���Ϊ�������ӳٺ�����ִ�У��ر��ʺ���Ϊ�ص�����ʹ�á�������ͨ����ָ����ӵ����ͱ�����
*/

/*������std::bind
std::bind���ɵ��ö����������һ����а󶨣��󶨺�Ľ������ʹ��std::function���档std::bind��Ҫ�������������ã�

���ɵ��ö����������󶨳�һ���º�����
ֻ�󶨲��ֲ��������ٿɵ��ö�����Ĳ�����

*/
double my_divide(double x, double y) { return x / y; }
void test02()//bind�� ��ͨ����
{
    auto fn_half = std::bind(my_divide, std::placeholders::_1, 1);
    auto fn_half2 = std::bind(my_divide, 100, 25);
    auto fn_half3 = std::bind(my_divide, 100, 25);
    std::cout << fn_half(10) << '\n';
    std::cout << fn_half2() << '\n';
}
struct Foo {
    void print_sum(int n1, int n2)
    {
        cout<<"n1:"<<n1<<",n2:"<<n2<<endl;
        std::cout << n1 + n2 << '\n';
    }
    int data = 10;
};
void test03()//bind �� ��Ա����
{
    Foo foo;
    //����1�����&����Ϊ�����������Զ��������Ա����ת���̺���ָ��
    //����2��ʹ�ö����Ա����ָ�룬����Ҫ֪����ָ�������ĸ�����

    auto f = std::bind(&Foo::print_sum, &foo, 95, std::placeholders::_1);
    f(5);//Ԥ���˵�һ��������95


    auto f2 = std::bind(&Foo::print_sum,&foo,std::placeholders::_1,std::placeholders::_2);
    f2(100,200);

    auto f3 = std::bind(&Foo::print_sum,&foo,std::placeholders::_2,std::placeholders::_1);
    f3(40,20);//�ı��˲���˳��

    
    auto f4 = std::bind(&Foo::print_sum, &foo,std::placeholders::_1,101);
    f4(10);

   // auto f5 = std::bind(&Foo::print_sum, &foo,std::placeholders::_2,101);
    //f5(20);//ռλ����˳������1��ʼ����������ָ��
 
}


//���� ��bind
class Base{
    public:
        Base()=default;
        void test() {
            auto func = Callable;
            
        }
        void Callable() {
            cout<<"hello,world";
        }
    private:
        int p1;
        int p2;
};


int main(void)
{
   // test01();//functional ���ֺ�������
    //test02();//bind  ���� 

    test03();
	
	return 0;
}

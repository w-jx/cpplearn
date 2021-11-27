#if 0
#include "wjxHeaders.h"


//这个有错误，调用45时，报错，0xC0000094: Integer division by zero。
//int fib(int n) {
//    vector<int> v;
//    v.reserve(n + 1);
//    for (int i = 0; i <= n; i++) {
//        if (i <= 1)
//            v.push_back(i);
//        else {
//            auto ret =(v[i - 1] + v[i - 2] )% static_cast<int>(1e+97);
//            v.push_back(ret);
//
//        }
//
//    }
//    return v.back();
//}
int fib2(int n) {
    vector<double> v;
    v.reserve(n + 1);
    for (int i = 0; i <= n; i++) {
        if (i <= 1)
            v.push_back(i);
        else {
           
            auto ret= fmod(v[i - 1] + v[i - 2], 1e9 + 7);
            v.push_back(ret);
        }

    }
    return v.back();//从_Ty转换成int 
}
//利用fmod函数
void test01()
{
    cout << fib2(45) << endl;

}
//手动实现fmod
void test02()
{

    double a = 6;
    double b = 4;
    double cd = a / b;
    int ci = a / b;
    cout << "cd=" << cd << ",ci=" << ci << endl;

    int e = 2;
    double c = 6.3;
    double ec = e * c;
    int ec2= e * c;
    cout << "ec=" << ec <<",ec2="<<ec2<< endl;



}
int main()
{
	//test01();
    test02();
	system("pause");
	return 0;
}


#endif
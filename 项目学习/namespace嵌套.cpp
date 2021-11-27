#include <iostream>

#define HEADERS_C8U1_H 1

#if HEADERS_C8U1_H

namespace vy
{
    namespace C8U1
    {
        enum
        {
            UDP_TAG = 0X6A,
            UDP_LEN = 1024,
        };
    }
}
#endif

struct size_test
{ //16
    int a;
    char b;
    double c;
};

struct size_test_2
{ //24
    char a;
    double b;
    int c;
};

auto test() -> void
{
    // int a = vy::C8U1::UDP_LEN;
    // std::cout << a << std::endl; //1024

    // int b = vy::C8U1::UDP_TAG;
    // std::cout << b << std::endl; //6*16+10 = 96+10 = 106

    std::cout << sizeof(size_test) << std::endl;

    std::cout << sizeof(size_test_2) << std::endl;
}
#pragma pack(push)
#pragma pack(1)
auto test2() -> void
{

    std::cout << sizeof(size_test) << std::endl;

    std::cout << sizeof(size_test_2) << std::endl;

}
#pragma pack(pop)
int main()
{
    //test();
    test2();
}
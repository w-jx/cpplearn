#include <iostream>

#pragma pack(push)
#pragma pack(1) //这其中的结构体按照1字节对齐
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
#pragma pack(pop) 

#pragma pack(push)
#pragma pack(4) //这其中的结构体按照4字节对齐
struct size_test_3
{ //16
    int a;
    char b;
    double c;
};

struct size_test_4
{ //24
    char a;
    double b;
    int c;
};
#pragma pack(pop)

struct size_test_5
{ //16
    int a;
    char b;
    double c;
};

struct size_test_6
{ //24
    char a;
    double b;
    int c;
};

namespace vy{
    namespace C8U1{
        enum{
            UDP_TAG = 0X6A,
            UDP_LEN = 1024,
        };
    }
}





int main()
{
    std::cout << sizeof(size_test) << std::endl;

    std::cout << sizeof(size_test_2) << std::endl;

    std::cout << sizeof(size_test_3) << std::endl;

    std::cout << sizeof(size_test_4) << std::endl;

    
    std::cout << sizeof(size_test_5) << std::endl;

    std::cout << sizeof(size_test_6) << std::endl;
}

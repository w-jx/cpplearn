#include <iostream>


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
    int a = vy::C8U1::UDP_LEN;
    std::cout<<a<<std::endl;//1024

    int b = vy::C8U1::UDP_TAG;
    std::cout<<b<<std::endl;//6*16+10 = 96+10 = 106
}
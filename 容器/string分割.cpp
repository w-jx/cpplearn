#include "wjxHeaders.h"

//c++11 之前
vector<string> split(string str)
{
    string delimiters = " ";
    string::size_type lastPos = str.find_first_not_of(delimiters,0);
    string::size_type Pos = str.find_first_of(delimiters,lastPos);
    vector<string> ret;
    while (string::npos!=Pos || string::npos!=lastPos) {
        ret.push_back(str.substr(lastPos,Pos-lastPos));
        lastPos = str.find_first_not_of(delimiters,Pos);
        Pos =str.find_first_of(delimiters,lastPos);
    }
    return ret;
}
//c++ 11后 regex
vector<string> split1(string str)
{
    std::regex  ws_re("\\s+");
    std::vector<string> ret( std::sregex_iterator(str.begin(),str.end(),ws_re,-1 ),std::sregex_token_iterator() );

    return ret;
}
void test01()
{
    auto ret = split1("I love china");
    printVector(ret);
}
int main()
{
    test01();
    
}
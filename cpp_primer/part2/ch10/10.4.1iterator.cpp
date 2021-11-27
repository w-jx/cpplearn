#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

void front_iterator()
{
    list<int> arrList{1,2,3,4,5};
    auto front_iter = front_inserter(arrList);
    
    for_each(arrList.begin(),arrList.end(),[](auto const &x){cout<<x<<" ";});
    cout<<endl;


    *front_iter =10;
    *front_iter =11;
    *front_iter =12;
    for_each(arrList.begin(),arrList.end(),[](auto const &x){cout<<x<<" ";});
    cout<<endl;
    front_insert_iterator<list<int>> fi_i(arrList);
    *fi_i = 13;
    *fi_i =14;
    for_each(arrList.begin(),arrList.end(),[](auto const &x){cout<<x<<" ";});
    cout<<endl;
}
int main()
{

}
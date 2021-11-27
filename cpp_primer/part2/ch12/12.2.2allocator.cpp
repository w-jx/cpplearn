#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;


void test01()
{
    allocator<int> alloc;
    auto const p = alloc.allocate(10);//int * 指针

    int arg = 0;
    //for_each(p,p+10,[&](auto ptr){alloc.construct(ptr,arg++);});
    for(int i=0;i<10;++i) {
        alloc.construct(p+i,arg++);
    }
    for(int i=0;i<10;++i) {
        cout<<p[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<10;++i) {
        alloc.destroy(p+i);
    }
    alloc.deallocate(p,10);
    
}

int main()
{
    test01();
}
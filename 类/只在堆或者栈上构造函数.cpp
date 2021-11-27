#if true
#include "../wjxHeaders.h"

class Heap_only
{
public:
    static Heap_only* get_instance() 
    {
        return new Heap_only;
    }
private:
     Heap_only()=default;
     Heap_only(const Heap_only&)=default;
     //Heap_only& operator=(const Heap_only&)=delete;
};


class Stack_only
{
public:
    
private:
     void* operator new(size_t );
     void  operator delete(void *p);
};


//实现只在堆上构造函数
void test01()
{
    //Heap_only Heap_only;//无法构造，构造函数私有了
    Heap_only* heap_only  = Heap_only::get_instance();
    
}

void test02(){
    Stack_only stk;
    //Stack_only *stkptr = new Stack_only();//无法构造
}

int main() {

	test01();
    //test02();
	return 0;
}

#endif
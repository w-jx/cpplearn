#include <stdio.h>
#include <stdlib.h>

//第一种情况,不加typedef
struct Person
{
    int Age;
    int Height;
};

void normal1()
{
    struct Person p1;
    p1.Age = 10;
    p1.Height = 170;
    printf("p1 age:%d,height:%d\n",p1.Age,p1.Height);
}
//第二种情况,不加typedef,定义结构体的同时声明p2,p3
struct Person2
{
    int Age;
    int Height;
} p2;
void normal2()
{
    
    p2.Age = 11;
    p2.Height = 150;
     printf("p2 age:%d,height:%d\n",p2.Age,p2.Height);
}
//第三种情况,typeef 起别名
typedef struct Person3
{
    int Age;
    int Height;
    int other;
}Person;

void normal3()
{
    Person p3;
    p3.Age=3;
    p3.Height=130;
     printf("p3 age:%d,height:%d\n",p3.Age,p3.Height);

     struct Person p4;//这两个类型不会出现矛盾
     p4.Age = 4;
     p4.Height =140;
     printf("p4 age:%d,height:%d\n",p4.Age,p4.Height);
}

typedef struct Person4
{
    int Age;
    int Height;
    int other;
}Person_4,*PPerson;

void normal4()
{
    PPerson p = (Person_4*)malloc(sizeof(Person_4));
    p->Age =5;
    p->Height = 150;
    printf("p5 age:%d,height:%d\n",p->Age,p->Height);
    free(p);
}
int main()
{
    normal1();
    normal2();
    normal3();
    normal4();
}
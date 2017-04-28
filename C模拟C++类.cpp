#include<bits/stdc++.h>
#ifndef C_Class

#define C_Class struct

#endif

C_Class A {

    C_Class A *A_this;

    void (*Foo)(C_Class A *A_this);

    int a;

    int b;

};

C_Class B{ //B继承了A

    C_Class B *B_this; //顺序很重要

    void (*Foo)(C_Class B *Bthis); //虚函数

    int a;

    int b;

    int c;

};

void B_F2(C_Class B *Bthis)

{

    printf("It is B_Fun\n");

}

void A_Foo(C_Class A *Athis)

{

    printf("It is A.a=%d\n",Athis->a);//或者这里

// exit(1);

// printf("纯虚 不允许执行\n");//或者这里

}

void B_Foo(C_Class B *Bthis)

{

    printf("It is B.c=%d\n",Bthis->c);

}

void A_Creat(struct A* p)

{

    p->Foo=A_Foo;

    p->a=1;

    p->b=2;

    p->A_this=p;

}

void B_Creat(struct B* p)

{

    p->Foo=B_Foo;

    p->a=11;

    p->b=12;

    p->c=13;

    p->B_this=p;

}

int main(int argc, char* argv[])

{

    C_Class A *ma,a;

    C_Class B *mb,b;

    A_Creat(&a);//实例化

    B_Creat(&b);

    mb=&b;

    ma=&a;

    ma=(C_Class A*)mb;//引入多态指针

    printf("%d\n",ma->a);//可惜的就是 函数变量没有private

    ma->Foo(ma);//多态

    a.Foo(&a);//不是多态了

    B_F2(&b);//成员函数，因为效率问题不使用函数指针

    return 0;

}

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

C_Class B{ //B�̳���A

    C_Class B *B_this; //˳�����Ҫ

    void (*Foo)(C_Class B *Bthis); //�麯��

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

    printf("It is A.a=%d\n",Athis->a);//��������

// exit(1);

// printf("���� ������ִ��\n");//��������

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

    A_Creat(&a);//ʵ����

    B_Creat(&b);

    mb=&b;

    ma=&a;

    ma=(C_Class A*)mb;//�����ָ̬��

    printf("%d\n",ma->a);//��ϧ�ľ��� ��������û��private

    ma->Foo(ma);//��̬

    a.Foo(&a);//���Ƕ�̬��

    B_F2(&b);//��Ա��������ΪЧ�����ⲻʹ�ú���ָ��

    return 0;

}

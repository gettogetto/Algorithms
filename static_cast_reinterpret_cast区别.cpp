#include<cstdio>
using namespace std;
struct A
{
	virtual void a() 
	{
		printf("A\n");
	}
};

struct B
{
	virtual void b() 
	{
		printf("B\n");
	}
};

struct C : A, B
{

};

int main()
{
	C c;
	printf("c��ַ��%p\n",&c);
	B* scast = static_cast<B*>(&c);//ת�����ֵַ�����仯 
	B* rcast = reinterpret_cast<B*>(&c);//��ֵַ���� 

	printf("scast��ַ��%p, rcast��ַ��%p\n", scast, rcast);

	scast->b(); //���B 
	rcast->b(); //��� A

	C* scast_back = static_cast<C*>(scast);
	C* rcast_back = reinterpret_cast<C*>(scast);
	printf("scast_back��ַ��%p, rcast_back��ַ��%p\n", scast_back, rcast_back);

	scast_back->a(); //���A
	rcast_back->a(); // ���B
	return 0;
}



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
	printf("c地址：%p\n",&c);
	B* scast = static_cast<B*>(&c);//转换后地址值发生变化 
	B* rcast = reinterpret_cast<B*>(&c);//地址值不变 

	printf("scast地址：%p, rcast地址：%p\n", scast, rcast);

	scast->b(); //输出B 
	rcast->b(); //输出 A

	C* scast_back = static_cast<C*>(scast);
	C* rcast_back = reinterpret_cast<C*>(scast);
	printf("scast_back地址：%p, rcast_back地址：%p\n", scast_back, rcast_back);

	scast_back->a(); //输出A
	rcast_back->a(); // 输出B
	return 0;
}



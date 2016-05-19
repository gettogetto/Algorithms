#include <iostream>
#include <stdlib.h>
using namespace std;
int(*retArray())[10]
{
	int(*a)[10];
	int i = 0;
	a = (int(*)[10])(calloc(10,sizeof(int)));
	for (i = 0; i < 10; i++)
	{
		(*a)[i] = i;
	}
	return a;

}
int( *func( int(&a)[3][3] ) )[3]
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = 3;
		}
	}
	return a;
}
int main()
{
	int(*b)[10];
	/*函数返回指向数组的指针*/
	b = retArray();
	printf("%d\n", (*b)[9]);
	free(b);

	///////////////////
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int(*a1)[3]=func(a);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a1[i][j] << " ";
		}
	}

	getchar();
	return 0;
}


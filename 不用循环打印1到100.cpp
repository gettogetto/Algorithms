//递归 
/*#include<iostream>
using namespace std;

bool print_n(int n,int N){
	return n<=N&&(cout<<n<<'\t')&&print_n(n+1,N);
}

int main(){
	print_n(1,100);
}*/

/***************************************************/
//构造函数法 
/*
#include<iostream>
using std::cout;


struct fool
{
	fool()
	{
	//	static int i = 1;
		cout << i++ << '\t';
	}
	static int i;
};
int fool::i=1;


int main()
{
	fool f[100];
	return 0;
}*/

/***************************************************/
//模板元
 
 #include<iostream>
 using namespace std;
 template<int n>
 struct A{
 	static void print(){
 		A<n-1>::print();
 		cout<<n<<'\t';
	 }
 };
 template<>
 struct A<1>{
 	static void print(){
 		cout<<1<<'\t';
	 }
 };
 int main(){
 	A<100>::print(); 
 }

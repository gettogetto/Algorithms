//����λ��0�㣬ÿ�ο�������������������ÿ����Ծ��һ����λ���ʵ���x��������Ҫ������Ծ��
 
#include<iostream>
#include<cmath>
using namespace std;


int Jump1(int x) {
	if (x==0) return 0;
	if (x<0) x=-x;
	int n=sqrt(2*x);
	while ((n+1)*n/2-x&1 || (n+1)*n/2<x)
		++n;
	return n;
}



int Jump2(int x){
	if(x==0) return 0;
	if(x<0) x=-x;
	int n=1;
	while((n+1)*n/2<x){//�ҵ���һ���ܺʹ���x�Ĳ��� 
		++n;
	}
	if(((n+1)*n/2-x)%2==0) return n;//���ò�ż��ʱ 
	else if(n%2!=0) return n+2;//n���� 
	else return n+1;//nż�� 
	
} 
int main(){
	int x;
	for(x=1;x<50;x++) 
		cout<<(Jump1(x)==Jump2(x))<<endl;
}

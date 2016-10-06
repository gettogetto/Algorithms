//蚂蚱位于0点，每次可以左右两个方向跳，每次跳跃多一个单位。问调到x处至少需要几次跳跃。
 
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
	while((n+1)*n/2<x){//找到第一次总和大于x的步数 
		++n;
	}
	if(((n+1)*n/2-x)%2==0) return n;//正好差偶数时 
	else if(n%2!=0) return n+2;//n奇数 
	else return n+1;//n偶数 
	
} 
int main(){
	int x;
	for(x=1;x<50;x++) 
		cout<<(Jump1(x)==Jump2(x))<<endl;
}

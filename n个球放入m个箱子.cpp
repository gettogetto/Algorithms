//n个球放入m个箱子，每个箱子可以放多个
#include<iostream>
using namespace std;
void solution(int* r,int* p,int n,int m){
	if(m==1){
		while(r!=p){
			cout<<*r<<" ";
			r++;
		}
		cout<<n<<endl;
		return;
	}else{
		for(*p=0;*p<=n;++*p){
			solution(r,p+1,n-*p,m-1);
		}
	}
} 
int main(){
	int n,m;
	cin>>n>>m;
	int *r=new int[m];
	solution(r,r,n,m);
}

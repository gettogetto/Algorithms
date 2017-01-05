#include<iostream>
#include<vector> 
using namespace std;
using LL=long long;
using Mat=vector<vector<int>>;
//快速幂 
LL power(int x,int n){
	LL res=1;
	while(n>0){
		if(n&1){
			res=res*x;
		}
		x*=x;
		n>>=1;
	}
	return res;
}
//快速矩阵幂实现lgn的斐波那契数列算法 
Mat matMul(const Mat& a,const Mat& b){
	Mat res(a.size(),vector<int>(b.size(),0));
	for(int i=0;i<a.size();i++){
		for(int k=0;k<a[0].size();k++){
			for(int j=0;j<b[0].size();j++){
				res[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return res;
}
Mat power(Mat x,int n){

	Mat res(x.size(),vector<int>(x.size(),1));
	while(n>0){
		if(n%2==1){
			res=matMul(res,x);
		}
		x=matMul(x,x);
		n>>=1;
	}
	return res;
}


int main(){
	Mat I(2,vector<int >(2,1));I[1][1]=0;
	int n; 
	for(int i=1;i<10;i++) cout<<power(I,i-1)[0][0]<<" ";
}

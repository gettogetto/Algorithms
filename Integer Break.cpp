    /*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

因数一定都小于4,即1,2,3,因为1对乘积无效，所以因数只能是2和3 
*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int integerBreak(int n) {
    vector<int>res{0,0,1,2,4,6,9};
	if(n==2) return 1;
	if(n==3) return 2;
	if(n==4) return 4;
	if(n==5) return 6;
	if(n==6) return 9;

    return 3*integerBreak(n-3);
}
int integerBreak2(int n){
	vector<int>res(max(7,n+1),1);
	res[2]=1,res[3]=2,res[4]=4,res[5]=6,res[6]=9;
	for(int i=7;i<=n;i++){
		res[i]=max(2*res[i-2],3*res[i-3]);
	}
	return res[n];
}
int main(){
	int n=2;
	while(n<=50){
		cout<<n<<" "<<integerBreak(n)<<" "<<integerBreak2(n)<<endl;
		n++;
	}
	
}

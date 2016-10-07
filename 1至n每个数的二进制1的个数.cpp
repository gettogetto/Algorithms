/*
题目：
给出一个数字n，列出 [0,n) 这个集合中每个数字的二进制包含多少个1.
例如：
数字5
0, 1, 2, 3, 4
包含1的个数分别是
0, 1, 1, 2, 1

用动态规划，n等于0时，1的个数是0，n大于等于2且为奇数，f(n)=f(n-1)+1，n大于等于2且为偶数，f(n)=f(n/2)
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> solution(int n){
	vector<int>count(n,0);
	count[1]=1;
	for(int i=2;i<n;i++){
		if(i&1) count[i]=count[i-1]+1;
		else count[i]=count[i/2];
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> count=solution(n);
	for(auto i:count) cout<<i<<" ";
	
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LPS(string str,int left,int right){
	//int len=str.length();
	//if(len==0) return 0;
	if(left>right) return 0;
	if(left==right) return 1;
	if(str[left]==str[right]){
		return LPS(str,left+1,right-1)+2;
	}else{
		return max(LPS(str,left+1,right),LPS(str,left,right-1));
	}
}
int LPS(string str){
	int n=str.size();
	if(n==0) return 0;
	vector<vector<int> >dp(n+1,vector<int>(n+1,0));
	for(int i=0;i<=n;i++) dp[i][i]=1;
	for(int delta=1;delta<=n;delta++){
		for(int start=0;start+delta<n;start++){
			if(str[start]==str[start+delta])
				dp[start+1][start+delta+1]=dp[start+2][start+delta]+2;
			else
				dp[start+1][start+delta+1]=max(dp[start+2][start+delta+1],dp[start+1][start+delta]);	
		}
	}
	return dp[1][n];
}
int main(){
	string str;
	while(getline(cin,str)){
		cout<<LPS(str,0,str.size()-1)<<" "<<LPS(str)<<endl;
	}
}

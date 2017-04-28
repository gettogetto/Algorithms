#include<bits/stdc++.h>
using namespace std;
const int maxn = 106;
int dp[maxn][maxn][maxn];//dp[l][r][d]表示区间［l,r］底色为d的最小花费
const int inf = 1e8;
string s;
int solve(int l,int r,int d){
    if(l>r)return 0;
    if(s[l]-'A'==d&&l==r)return dp[l][r][d]=0;
    if(l==r)return dp[l][r][d]=1;
    if(dp[l][r][d]!=-1)return dp[l][r][d];
    dp[l][r][d]=inf;
    for(int i=0;i<26;i++){
        dp[l][r][d]=min(dp[l][r][d],solve(l,r,i)+1);
    }
    if(s[l]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l+1,r,d));
    if(s[r]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l,r-1,d));
    for(int i=l+1;i<r;i++){
        if(s[i]-'A'==d){
            dp[l][r][d]=min(dp[l][r][d],solve(l,i-1,d)+solve(i+1,r,d));
        }
    }
    return dp[l][r][d];
}
//法二 
int func(string str){
	int n = str.size();
	vector<vector<int>> res(n,vector<int>(n));
	for(int i=0;i<n;++i)
		res[i][i] = 1;
	for(int k=1;k<n;++k){
		for(int left=0;left<n-k;++left){
			int right = left + k;
			int minval = INT_MAX;
			for(int j=left;j<right;++j){
				if(minval > (res[left][j] + res[j+1][right])){
					minval = res[left][j] + res[j+1][right];
					res[left][right] = (str[left] == str[right] ?  minval - 1 : minval) ;
				}
			}
		}
	}
	return res[0][n-1];
}
int main(){
    while(cin>>s){
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,s.size()-1,27)<<" "<<func(s)<<endl;
    }
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*int solution(string str1,string str2)
{
	int len1=str1.size();
	int len2 = str2.size();
	vector<vector<int> >dp(len1,vector<int>(len2,0));

	if(str1[0]==str2[0]) dp[0][0]=0;
	else dp[0][0]=4;

	for(int j=1;j<len2;j++){
		if(str1[0]!=str2[0]) dp[0][j]=2+j+1+2;
		else dp[0][j]=j+2;
	}
	for(int i=1;i<len1;i++) {
		if(str1[0]!=str2[0]) dp[i][0]=2+1+2;
		else dp[i][0]=2;
	}

	for(int i=1;i<len1;i++){
		for(int j=1;j<len2;j++){
			if(str1[i]==str2[j]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				for(int k=0;k<i;k++) dp[i][j]=min(dp[k][j],dp[i][j])+2;
				for(int k=0;k<j;k++) dp[i][j]=min(dp[i][k]+j-k,dp[i][j])+2;
			}
		}
	}
	return dp[len1-1][len2-1];
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string str1,str2;
		cin>>str1>>str2;
		cout<<solution(str1,str2)<<endl;
	}
}*/
//1到n-1有一个出现2次，其他一次，找出重复元素
 //3种方法 
int check1(int nums[]) {
	{
		int slow =0;
		int fast =0;
		while(true) {
			slow=nums[slow];
			fast=nums[nums[fast]];
			if(slow == fast)
				break;
		}
		fast = 0;
		while(true) {
			slow=nums[slow];
			fast=nums[fast];
			if(slow==fast)return slow;
		}
	}
}
int check2(int nums[],int n) {
	int x=0;
	for(int i=0;i<n;i++){
		x=x^nums[i]^i;
	}
	return x;
}
int check3(int nums[],int n) {
	int x=0;
	for(int i=0;i<n;i++){
		x+=nums[i]-i;
	}
	return x;
}
int main() {
	int nums[]= {5,4,3,3,2,1};
	cout<<check1(nums)<<" "<<check2(nums,6)<<" "<<check3(nums,6);
}

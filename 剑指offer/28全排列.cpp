//无法处理重复元素 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void helper(string &str,int s){
	if(s==str.size()) cout<<str<<endl;
	for(int i=s;i<str.size();i++){
		swap(str[s],str[i]);
		helper(str,s+1);
		swap(str[s],str[i]);//回溯，注意形参str如不是引用，则删掉此句 
	}
}
void permutation(string &str){
	helper(str,0);
}
////////////////////////////////////////////////
//处理重复元素 
bool nextPermutation(vector<int> &num) {
	if (num.size() <= 1) return false;
    
	int i = (int)num.size() - 1;
	while (i > 0 && num[i] <= num[i-1])//找出逆序的后缀 
		--i;
	if (i == 0) {
		//reverse(num.begin(), num.end());
		return false;
	}
	
	--i;
	int j = (int)num.size() - 1;
	while (!(num[i] < num[j])) //找到第一个比i点大的元素 
		--j;
	
	swap(num[i], num[j]);//交换位置 
	reverse(num.begin() + i + 1, num.end());//反转后面的逆序后缀 
	return true;
}
int main(){
	string str;
	cin>>str;
	permutation(str);
////////////////////////
	vector<int> v={1,2,3};
	do{
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	} while(nextPermutation(v));
	
	
}

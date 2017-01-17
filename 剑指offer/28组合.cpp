//输出字符串的组合
//例 123输出1，2,3,12,13,23,123 
#include<string>
#include<iostream>
using namespace std;
void helper(const string& str,int number,int i,string& res){//number为选出的字符个数，i为当前下标 
	if(number==0&&i==str.size()) cout<<res<<endl;
	if(i==str.size()) return;

	res+=str[i];//要当前的字符 
	helper(str,number-1,i+1,res);
	res.pop_back();//回溯 
	
	helper(str,number,i+1,res);//不要当前的字符 
}
void combination(const string& str){
	for(int n=1;n<=str.size();n++){//从字符串中选择n个字符组合在一起 
		string res="";
		helper(str,n,0,res);
	}
}
int main(){
	string str;
	cin>>str;
	combination(str);
}

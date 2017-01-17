
#include<iostream>
#include<string>
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

int main(){
	string str;
	cin>>str;
	permutation(str);
}

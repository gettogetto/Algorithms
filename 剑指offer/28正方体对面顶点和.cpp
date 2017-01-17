//28附加习题 ，8个数放到正方体8个顶点，求出令正方体3组相对的面的顶点和相等，求所有放法 
//仍是全排列问题 
#include<iostream>
#include<vector>
using namespace std;
bool isok(vector<int> &str){
	return (str[0]+str[1]+str[2]+str[3]==str[4]+str[5]+str[6]+str[7])&&
	(str[0]+str[2]+str[4]+str[6]==str[1]+str[3]+str[5]+str[7])&&
	(str[0]+str[1]+str[4]+str[5]==str[2]+str[3]+str[6]+str[7]);
}
void helper(vector<int> &str,int s){
	if(s==str.size()&&isok(str)){
		for(auto num:str) cout<<num<<" ";
		cout<<endl;
	}
	for(int i=s;i<str.size();i++){
		swap(str[s],str[i]);
		helper(str,s+1);
		swap(str[s],str[i]);//回溯，注意形参str如不是引用，则删掉此句 
	}
}
void permutation(vector<int> &str){
	helper(str,0);
}

int main(){
	vector<int> str={1,2,3,4,5,6,7,8};
	
	permutation(str);
}

//28����ϰ�� ��8�����ŵ�������8�����㣬�����������3����Ե���Ķ������ȣ������зŷ� 
//����ȫ�������� 
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
		swap(str[s],str[i]);//���ݣ�ע���β�str�粻�����ã���ɾ���˾� 
	}
}
void permutation(vector<int> &str){
	helper(str,0);
}

int main(){
	vector<int> str={1,2,3,4,5,6,7,8};
	
	permutation(str);
}

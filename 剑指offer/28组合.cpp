//����ַ��������
//�� 123���1��2,3,12,13,23,123 
#include<string>
#include<iostream>
using namespace std;
void helper(const string& str,int number,int i,string& res){//numberΪѡ�����ַ�������iΪ��ǰ�±� 
	if(number==0&&i==str.size()) cout<<res<<endl;
	if(i==str.size()) return;

	res+=str[i];//Ҫ��ǰ���ַ� 
	helper(str,number-1,i+1,res);
	res.pop_back();//���� 
	
	helper(str,number,i+1,res);//��Ҫ��ǰ���ַ� 
}
void combination(const string& str){
	for(int n=1;n<=str.size();n++){//���ַ�����ѡ��n���ַ������һ�� 
		string res="";
		helper(str,n,0,res);
	}
}
int main(){
	string str;
	cin>>str;
	combination(str);
}

    /*
	Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//s:����
//preiĳ���ֽڵ���ʼ�±�
//curi��ǰ�±�
//cnt�Ѿ���ɵķֽ���Ŀ
//path�����γɵĽ��
//res������кϸ��� 
void helper(string s,int prei,int curi,int cnt,string path,vector<string>& res){
	
	if(curi==s.size()) return;//��β������ 

    int curval=stoi(s.substr(prei,curi-prei+1));//��ǰ�ֽڵĴ�С 
    if(curval>255) return;//����255������ 

    if(cnt==3&&curi==s.size()-1){//�������һ���ַ�����������3���ֽ� 
        string tmp=path+("."+to_string(curval));//�������һ���ֽ� 
		if(tmp.size()==s.size()+3) res.push_back(tmp);//���ս����������볤3���ַ����ܷ��������� 
		return;
    }
    
    string tmp=path+(cnt==0?to_string(curval):"."+to_string(curval));//prei��curi��Ϊһ���ֽ� ������;����� 
    helper(s,curi+1,curi+1,cnt+1,tmp,res);
    
    helper(s,prei,curi+1,cnt,path,res);//�����ֽڣ�������һ���ַ� 

}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.size()>12) return res;//ԭʼ���볬��12���ַ� 
    helper(s,0,0,0,"",res);
    return res;
}
int main(){
	string s="25525511135";
	vector<string> res=restoreIpAddresses(s);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}

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
//s:输入
//prei某个分节的起始下标
//curi当前下标
//cnt已经完成的分节数目
//path正在形成的结果
//res存放所有合格结果 
void helper(string s,int prei,int curi,int cnt,string path,vector<string>& res){
	
	if(curi==s.size()) return;//逾尾，返回 

    int curval=stoi(s.substr(prei,curi-prei+1));//当前分节的大小 
    if(curval>255) return;//超过255，返回 

    if(cnt==3&&curi==s.size()-1){//到达最后一个字符，并且已有3个分节 
        string tmp=path+("."+to_string(curval));//加上最后一个分节 
		if(tmp.size()==s.size()+3) res.push_back(tmp);//最终结果必须比输入长3个字符才能放入结果数组 
		return;
    }
    
    string tmp=path+(cnt==0?to_string(curval):"."+to_string(curval));//prei至curi作为一个分节 加在中途结果后 
    helper(s,curi+1,curi+1,cnt+1,tmp,res);
    
    helper(s,prei,curi+1,cnt,path,res);//不做分节，继续下一个字符 

}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.size()>12) return res;//原始输入超过12个字符 
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

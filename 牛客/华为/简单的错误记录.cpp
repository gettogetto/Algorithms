/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325


输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子:
E:\V1R2\product\fpgadrive.c 1325

输出例子:
fpgadrive.c 1325 1
*/
#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
using namespace std;  
struct error{
    string filename;
    int line;
    int count;
};
void settleerror(string name,int line,vector<error>& v){
    int i=name.find_last_of('\\');
    string s_name=name.substr(i+1);
    error e={s_name,line,1};
    bool haved=0;
    for(int i=0;i<(int)v.size();i++){
        if(v[i].filename==s_name&&v[i].line==line){
            v[i].count++;
            haved=1;
            break;
        }
    }
    if(haved==0) v.push_back(e);
    
    
}
static bool comp(const error&e1,const error& e2){
    return e1.count>e2.count;
}
int main(){
    string str;
    int line;
    vector<error> v;
    while(cin>>str>>line){
        settleerror(str,line,v);
    }
    //sort(v.begin(),v.end(),[](error& e1,error& e2){return e1.count>e2.count;});
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<8;i++){
        error e=v[i];
        if(e.filename.length()>16) e.filename=e.filename.substr(e.filename.size()-16);
        cout<<e.filename<<" "<<e.line<<" "<<e.count<<endl;
    }
}

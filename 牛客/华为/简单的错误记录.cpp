/*
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš� 
����:
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��

��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

    �ļ�·��Ϊwindows��ʽ

    �磺E:\V1R2\product\fpgadrive.c 1325


�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1 

    ���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������

    �������8����¼����ֻ���ǰ8����¼.

    ����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�

��������:
E:\V1R2\product\fpgadrive.c 1325

�������:
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

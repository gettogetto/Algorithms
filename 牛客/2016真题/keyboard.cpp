/*
The numberic keypad on your mobile phone looks like below:
123
456
789
 0
 suppose you are holding your mobile phone with single hand. Your thumb points at digit 1. Each time you can 1)press the digit your thumb pointing at.2)moveyour thumb right,3)move your thumb down. Moving your thumb left or up is not allowed.
 By using the numeric keypad under above constrains, you can produce some numbers like 177 or 480 while producing other numbers like 590 or 52 is impossible.
 Given a number K, find out the maximum number less than or equal to K that can be produced.

输入描述:
the first line contains an integer T, the number of testcases.
Each testcase occupies a single line with an integer K.

For 50%of the data ,1<=K<=999.
For 100% of the data, 1<=K<=10^500,t<=20.


输出描述:
for each testcase output one line, the maximum number less than or equal to the corresponding K that can be produced.

输入例子:
3
25
83
131

输出例子:
25
80
129
8、 

//超时 ！！！！！！ 
/*#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string>&v,int i,int j,string cur,string &res,string &allow){
    if(i==3&&j==0||i==3&&j==2) return;
    if(i<0||i>3||j<0||j>2) return;
    if(cur.size()>=allow.size()) return;
    
    //不按
    dfs(v,i+1,j,cur,res,allow);
    dfs(v,i,j+1,cur,res,allow);
    
    //按
    cur+=v[i][j];cout<<res<<endl;
    if(cur.size()<allow.size()||cur.size()==allow.size()&&cur<=allow){
        if(cur.size()>res.size()||cur.size()==res.size()&&cur>res){
            res=cur;
        }
    }
    dfs(v,i,j,cur,res,allow);
    dfs(v,i+1,j,cur,res,allow);
    dfs(v,i,j+1,cur,res,allow);   
}

//

int main(){
    vector<string> v={"123","456","789","000"};
    int times;
    cin>>times;
    while(times--){
        string k;
        cin>>k;
        string res="0";
        string cur="";
        dfs(v,0,0,cur,res,k);
        cout<<res<<endl;
    }
}
*/

//法二 

#include <iostream>
using namespace std;
void locate(int digit,int &x,int &y){
    digit=digit?--digit:10;
    x=digit/3; //行数
    y=digit%3; //列数
}
bool reach(int x,int y)
    //判断x能否到达y
{
    int x0,y0,x1,y1;
    locate(x-'0',x0,y0);
    //获取x的行 列
    locate(y-'0',x1,y1);
    //获取y的行 列
    return x0<=x1&&y0<=y1;
}
    int main(){
    
        int T;
        for(cin>>T;T--;)
        {
            string K;
            cin>>K;
            for(int i=0;i<K.size()-1;i++) //个位不用参加循环
            {
				while(!reach(K[i],K[i+1])) 
                {
                    if(--K[i+1]<'0')
                        K[i--]--;//回溯 
                    for(int j=i+2;j<K.size();j++)

                        K[j]='9';

                }
            }
           
            cout<<K<<endl;


        }

}




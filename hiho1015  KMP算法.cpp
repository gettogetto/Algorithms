/*
输入
第一行一个整数N，表示测试数据组数。

接下来的N*2行，每两行表示一个测试数据。在每一个测试数据中，第一行为模式串，由不超过10^4个大写字母组成，第二行为原串，由不超过10^6个大写字母组成。

其中N<=20

输出
对于每一个测试数据，按照它们在输入中出现的顺序输出一行Ans，表示模式串在原串中出现的次数。

样例输入
5
HA
HAHAHA
WQN
WQN
ADA
ADADADA
BABABB
BABABABABABABABABB
DAD
ADDAADAADDAAADAAD
样例输出
3
1
3
1
0

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getNext(const string& p,vector<int>&next)
{
    next.resize(p.size()+1);
    next[0]=-1;
    int i=0,j=-1;
    
    while(i<p.size())
    {
        if(j==-1||p[i]==p[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

int kmp(const string& s,const string& p)
{
	int count=0;
    vector<int>next;
    getNext(p,next);
    int i = 0, j = 0;
    while(i != s.length() )
    {
        
        if (j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else if(j<p.length())
        {
            j = next[j];
        }
        if(j==p.length()) {
			count++;
			j=next[j];
		}
    }

    return count;
}

int main()
{
    int n;
    cin>>n;
    string s,p;
    for(int i=0;i<n;i++)
    {
        cin>>p>>s;
 
        cout<<kmp(s,p)<<endl;

    }
    return 0;
}

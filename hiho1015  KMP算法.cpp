/*
����
��һ��һ������N����ʾ��������������

��������N*2�У�ÿ���б�ʾһ���������ݡ���ÿһ�����������У���һ��Ϊģʽ�����ɲ�����10^4����д��ĸ��ɣ��ڶ���Ϊԭ�����ɲ�����10^6����д��ĸ��ɡ�

����N<=20

���
����ÿһ���������ݣ����������������г��ֵ�˳�����һ��Ans����ʾģʽ����ԭ���г��ֵĴ�����

��������
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
�������
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

/*[编程题] 数列还原
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。 
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。


输出描述:
输出一行表示合法的排列数目。

输入例子:
5 5
4 0 0 2 0

输出例子:
2*/

#include<iostream>
#include<vector>
 
using namespace std;
 
bool find(vector<int> v,int n)    //查询v中是否存在整数n
{
    for(int i = 0;i<v.size();++i)
        if(v[i]==n)
            return true;
    return false;
}
 
vector<vector<int>> pv; //全局变量
 
void Perm(vector<int> &v,int st)   //对v中的数字进行全排列
{
    if(st == v.size())
        pv.push_back(v);
    else
    {
        for(int i = st;i<v.size();++i)
        {
            swap(v[i],v[st]);
            Perm(v,st+1);
            swap(v[i],v[st]);
        }
    }
}
 
void change(vector<int> &v,vector<int> subv,vector<int> vpos)//将v中的0用全排之后的数字分别代替
{
    for(int i = 0;i<vpos.size();++i)
        v[vpos[i]] = subv[i];
}
 
int cal(vector<int> v)  //计算顺序对的个数
{
    int cnt = 0;
    for(int i = 0;i<v.size()-1;++i)
        for(int j = i+1;j<v.size();++j)
            if(v[i]<v[j])
                ++cnt;
    return cnt;
}
 
int main()
{
    int n,k,tmp;
    while(cin>>n>>k)
    {
        vector<int> v,subv,vpos;
        for(int i = 0;i<n;++i)
        {
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i = 0;i<v.size();++i)
            if(v[i]==0)
                vpos.push_back(i);   //记录下vector<int>中0的位置
        for(int i = 1;i<=n;++i)
            if(!find(v,i))
                subv.push_back(i);
        Perm(subv,0);
        vector<int> vcnt;
        for(int i = 0;i<pv.size();++i)
        {
            change(v,pv[i],vpos);
            vcnt.push_back(cal(v));
        }
        int vcntk = 0;
        for(int i = 0;i<vcnt.size();++i)
            if(vcnt[i]==k)
                ++vcntk;
        cout<<vcntk<<endl;
    }
 
    return 0;
}

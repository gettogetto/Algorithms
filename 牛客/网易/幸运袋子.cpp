/*
һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ� 
��������:
��һ������һ��������n(n �� 1000)
�ڶ���Ϊn����������xi(xi �� 1000)


�������:
������Բ��������˵Ĵ�����

��������:
3
1 1 1

�������:
2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<int>&v,int i,int sum,int product){
    if(i>=(int)v.size()) return sum>product;
    if(v[i]>1&&sum<product) return 0;
    int res1= dfs(v,i+1,sum+v[i],product*v[i]);//ѡ 
    while(i<(int)v.size()-1&&v[i+1]==v[i]) i++;
    int res2= dfs(v,i+1,sum,product);//��ѡ 
    return res1+res2;
}
int solve(vector<int>&v){
	sort(v.begin(),v.end());
    return dfs(v,0,0,1);
    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& i:v) cin>>i;
    cout<<solve(v);
}


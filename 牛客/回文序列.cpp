/*
���һ��������������֮���ԭ������һ���ľͳ���������������Ϊ�������С����磺
{1, 2, 1}, {15, 78, 78, 15} , {112} �ǻ�������, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} ���ǻ������С�
���ڸ���һ���������У�����ʹ��һ��ת��������
ѡ�������������ڵ�����Ȼ��������Ƴ������������������������ֵĺͲ��뵽��������֮ǰ��λ��(ֻ����һ����)��
���ڶ�����������Ҫ���������Ҫ���ٴβ������Խ����ɻ������С�

��������:
����Ϊ���У���һ��Ϊ���г���n ( 1 �� n �� 50)
�ڶ���Ϊ�����е�n������item[i]  (1 �� iteam[i] �� 1000)���Կո�ָ���


�������:
���һ��������ʾ������Ҫ��ת������

��������:
4
1 1 1 3

�������:
2
*/
#include<iostream>
#include<vector>
using namespace std;
int func(vector<int>&v){
    int n=v.size();
    if(n==0) return 0;
    if(n==1) return 1;
    int left=0,right=n-1,res=0;
    while(left<right){
        if(v[left]==v[right]) left++,right--;
        else if(v[left]<v[right]){
            v[left+1]=v[left]+v[left+1];
            left++;
            res++;
        }else{
            v[right-1]=v[right]+v[right-1];
            right--;
            res++;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    cout<<func(v)<<endl;
}


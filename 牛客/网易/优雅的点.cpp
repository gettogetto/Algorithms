/*
С����һ��Բ��������ԭ���Բ��С��֪��Բ�İ뾶��ƽ����С����Ϊ��Բ�ϵĵ���Һ������궼�������ĵ������ŵģ�С��������Ѱ��һ���㷨��������ŵĵ�ĸ������������������
���磺�뾶��ƽ�����Ϊ25
���ŵĵ���У�(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)��һ��12���㡣 
��������:
����Ϊһ����������ΪԲ�뾶��ƽ��,��Χ��32λint��Χ�ڡ�


�������:
���Ϊһ����������Ϊ���ŵĵ�ĸ���

��������:
25

�������:
12
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int func(int r2){
    int res=0;
    int r=sqrt(r2);
    int left=0,right=sqrt(r2);
    while(left<=right){
        int tmp=left*left+right*right;
        if(tmp==r2) res+=2*((left&&right)?(left!=right?4:2):2),right--,left++;
        else if(tmp<r2) left++;
        else right--;
    }
    return res;
}
int main(){
    int r2;
    cin>>r2;
    cout<<func(r2);
}

/*
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������ 
��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)


�������:
���һ�������Էŵĵ�����

��������:
3 2

�������:
4
*/

#include<iostream>  
#include<cstring>  
#include<vector>  
#include<algorithm>  
using namespace std;  
  
int num[51][32];  
  
int main(){  
    int n,m;  
    cin>>n>>m;  
    int nn = n / 4 * 2;  
    if(n % 4 == 1) nn++;  
    if(n % 4 >= 2) nn+=2;  
    int ans = m / 4 * n * 2;  
    if( m % 4 == 1) ans += nn;  
    if( m % 4 == 2) ans += nn * 2;  
    if( m % 4 == 3) ans += nn + n;  
    cout<<ans<<endl;  
  
}  

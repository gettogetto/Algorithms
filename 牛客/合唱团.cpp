
/*
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻��� 
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��


�������:
���һ�б�ʾ���ĳ˻���

��������:
3
7 4 7
2 50

�������:
49
*/
//f [ i ] [ j ] [ ��� / ��С ]
//�ֱ��ʾ���Ե�i����Ϊ���һ����Ҳ�Ǳ�ѡ�ģ��ˣ���������ˣ��Ѿ�ѡ�� j ���ˣ������ܵĳ˻�����С���ܵĳ˻���
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int a[55];
ll f[55][15][2];
 
int main(){
    int n,kk,d;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    scanf("%d%d",&kk,&d);
    ll ans=0;
    for(int i=1;i<=n;i++){
        f[i][1][0]=f[i][1][1]=a[i];
        for(int j=2;j<=kk;++j){
            for(int k=i-1;k>=max(i-d,1);--k){
                f[i][j][0]=max(f[i][j][0],max(f[k][j-1][0]*a[i],f[k][j-1][1]*a[i]));
                f[i][j][1]=min(f[i][j][1],min(f[k][j-1][0]*a[i],f[k][j-1][1]*a[i]));
            }
        }
        ans=max(ans,max(f[i][kk][0],f[i][kk][1]));
    }
    printf("%lld\n",ans);
    return 0;
}


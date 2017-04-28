#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;

int a[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int A,B;
        scanf("%d%d",&A,&B);
        a[A]++;
        a[B+1]--;
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum%2==0)printf("0");
        else printf("1");
    }
    printf("\n");
}

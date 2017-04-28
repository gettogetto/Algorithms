#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+7;
vector<int> E[maxn];
int n,m;
int vis[maxn],cnt=0;
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<E[x].size();i++){
        if(!vis[E[x][i]])
            dfs(E[x][i]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt-1<<endl;
}

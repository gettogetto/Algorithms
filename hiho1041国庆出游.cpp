/*
描述
小Hi和小Ho准备国庆期间去A国旅游。A国的城际交通比较有特色：它共有n座城市(编号1-n)；城市之间恰好有n-1条公路相连，形成一个树形公路网。小Hi计划从A国首都(1号城市)出发，自驾遍历所有城市，并且经过每一条公路恰好两次——来回各一次——这样公路两旁的景色都不会错过。



令小Hi苦恼的是他的小伙伴小Ho希望能以某种特定的顺序游历其中m个城市。例如按3-2-5的顺序游历这3座城市。(具体来讲是要求：第一次到达3号城市比第一次到达2号城市早，并且第一次到达2号城市比第一次到达5号城市早)。



小Hi想知道是否有一种自驾顺序满足小Ho的要求。

输入
输入第一行是一个整数T(1<=T<=20)，代表测试数据的数量。

每组数据第一行是一个整数n(1 <= n <= 100)，代表城市数目。

之后n-1行每行两个整数a和b (1 <= a, b <= n)，表示ab之间有公路相连。

之后一行包含一个整数m (1 <= m <= n)

最后一行包含m个整数，表示小Ho希望的游历顺序。

输出
YES或者NO，表示是否有一种自驾顺序满足小Ho的要求。

样例输入
2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 7 2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 2 7
样例输出
YES
NO
*/ 

#include<iostream>
#include<vector>
#include<bitset>
#include<memory.h>
using namespace std;

const int MAXN = 101;
vector<int> adj[MAXN];//邻接表 
bitset<MAXN> haschild[MAXN];//子孙位置一 
int arr[MAXN];//计划顺序 
int graMat[MAXN][MAXN];//是否相邻 


void getChild(int u = 1,int parent = -1){
	haschild[u][u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(v==parent) continue;
		getChild(v,u);
		haschild[u] |= haschild[v];
	}
}


bool dfs(int a[],int &id,int m,int u,int parent)
{
	if(id<m&&a[id]==u) id++;
	if(id==m) return true;
	while(id<m){
		int next = a[id];
		int curindex=id;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(v==parent) continue;
			if(haschild[v][next]&&graMat[u][v]){
				graMat[u][v] = 0;//走过置零 
				if(dfs(a,id,m,v,u)) return true;
				
			} 
		}
		if(id==curindex) break;
	}
	return false;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			adj[i].clear();
			haschild[i].reset();
		}
		memset(graMat,0,sizeof graMat);
		for(int i=1;i<=n-1;i++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			graMat[a][b]=graMat[b][a]=1;
		}
		
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>arr[i];
		} 
		getChild();
		int id=0;
		
		if(dfs(arr,id,m,1,-1) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
} 


/*
����
СHi��СHo׼�������ڼ�ȥA�����Ρ�A���ĳǼʽ�ͨ�Ƚ�����ɫ��������n������(���1-n)������֮��ǡ����n-1����·�������γ�һ�����ι�·����СHi�ƻ���A���׶�(1�ų���)�������Լݱ������г��У����Ҿ���ÿһ����·ǡ�����Ρ������ظ�һ�Ρ���������·���Եľ�ɫ����������



��СHi���յ�������С���СHoϣ������ĳ���ض���˳����������m�����С����簴3-2-5��˳��������3�����С�(����������Ҫ�󣺵�һ�ε���3�ų��бȵ�һ�ε���2�ų����磬���ҵ�һ�ε���2�ų��бȵ�һ�ε���5�ų�����)��



СHi��֪���Ƿ���һ���Լ�˳������СHo��Ҫ��

����
�����һ����һ������T(1<=T<=20)������������ݵ�������

ÿ�����ݵ�һ����һ������n(1 <= n <= 100)�����������Ŀ��

֮��n-1��ÿ����������a��b (1 <= a, b <= n)����ʾab֮���й�·������

֮��һ�а���һ������m (1 <= m <= n)

���һ�а���m����������ʾСHoϣ��������˳��

���
YES����NO����ʾ�Ƿ���һ���Լ�˳������СHo��Ҫ��

��������
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
�������
YES
NO
*/ 

#include<iostream>
#include<vector>
#include<bitset>
#include<memory.h>
using namespace std;

const int MAXN = 101;
vector<int> adj[MAXN];//�ڽӱ� 
bitset<MAXN> haschild[MAXN];//����λ��һ 
int arr[MAXN];//�ƻ�˳�� 
int graMat[MAXN][MAXN];//�Ƿ����� 


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
				graMat[u][v] = 0;//�߹����� 
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


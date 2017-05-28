 //Trajan是求解有向图强连通分量的线性时间的算法
 #include<bits/stdc++.h>
 using namespace std;
 #define N 101

 int top=-1;//栈顶下标
 int timestamp=1;//表示节点被访问的次序
 int dfn[N]; //dfn[i]：深度优先搜索遍历时节点i被搜索的次序。
 int low[N]; //low[i]：节点i能够回溯到的最早位于栈中的节点。


 bool instack[N]={0};//是否在栈中
 int stak[N];//栈

 int nodenum=6;//节点数目
 int matrix[N][N]={{0,1,1,0,0,0},
 					{0,0,0,1,0,0},
					 {0,0,0,1,1,0},
					 {1,0,0,0,0,1},
					 {0,0,0,0,0,1},
					 {0,0,0,0,0,0}};//图的邻接矩阵

 int components=0;//联通分量数量

 void trajan(int u){
    dfn[u]=low[u]=timestamp++;
    stak[++top]=u;
    instack[u]=1;
    for(int v=0;v<nodenum;v++){
        if(matrix[u][v]){//枚举u直接可达的节点v
            if(!dfn[v]){//v没访问过
                trajan(v);
                low[u]=min(low[u],low[v]);//更新能找的到祖先
            }else{//如果访问过了
                if(instack[v]) low[u]=min(low[u],dfn[v]);

                //instack这个判断条件很重要，这样可以避免已经确定在其他联通图的v,因为u到v的单向边而影响到u的low
                //也就是已经确定了的联通图要剔除掉，剔除的办法就是判断其还在栈中，因为已经确定了的连通图的点
               //instack在下面的do while中已经设为0了(即已经从栈中剔除了)
            }
        }
    }
    //DFN值和low值相等的节点是该连通图中第一个被访问到的节点，又根据栈的特性，
    //则该节点在最里面。所以能够通过不停的弹栈，
    //直到弹出该DFN值和low值相同的节点来弹出该连通图中所有的节点。
    if(low[u]==dfn[u]){
        components++;
        int t;
        do{
            t=stak[top--];
            cout<<t<<" ";
            instack[t]=0;//弹出
        }while(t!=u);
        cout<<endl;
    }
 }
 int main(){
    memset(dfn,0,sizeof(dfn));                  //数据的初始化
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    trajan(0);
 }


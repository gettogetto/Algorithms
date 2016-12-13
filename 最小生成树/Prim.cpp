#include<iostream>
#include<memory.h>
#define INF 10000
using namespace std;
const int N = 6;
bool visit[N];
int dist[N] = { 0, };
int graph[N][N] = { {INF,7,4,INF,INF,INF},   //INF代表两点之间不可达
                    {7,INF,6,2,INF,4}, 
                    {4,6,INF,INF,9,8}, 
                    {INF,2,INF,INF,INF,7}, 
                    {INF,INF,9,INF,INF,1}, 
                    {INF,4,8,7,1,INF}
                  };
int prim(int cur)
{
    int index = cur;
    int sum = 0;
    int i = 0;
    int j = 0;
    cout << index << " ";
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for (i = 0; i < N; i++)
        dist[i] = graph[cur][i];//初始化，每个与a邻接的点的距离存入dist
    for (i = 1; i < N; i++)
    {
        int minor = INF;
        for (j = 0; j < N; j++)
        {
            if (!visit[j] && dist[j] < minor)          //找到未访问的点中，距离当前最小生成树距离最小的点
            {
                minor = dist[j];
                index = j;
            }
        }
        visit[index] = true;
        cout << index << " ";
        sum += minor;
        for (j = 0; j < N; j++)
        {
            if (!visit[j] && dist[j]>graph[index][j])      //执行更新，如果点距离当前点的距离更近，就更新dist
            {
                dist[j] = graph[index][j];
            }
        }
    }
    cout << endl;
    return sum;               //返回最小生成树的总路径值
}
int main()
{
    cout << prim(0) << endl;//从顶点a开始
    return 0;
}

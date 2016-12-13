#include<iostream>
#include<memory.h>
#define INF 10000
using namespace std;
const int N = 6;
bool visit[N];
int dist[N] = { 0, };
int graph[N][N] = { {INF,7,4,INF,INF,INF},   //INF��������֮�䲻�ɴ�
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
        dist[i] = graph[cur][i];//��ʼ����ÿ����a�ڽӵĵ�ľ������dist
    for (i = 1; i < N; i++)
    {
        int minor = INF;
        for (j = 0; j < N; j++)
        {
            if (!visit[j] && dist[j] < minor)          //�ҵ�δ���ʵĵ��У����뵱ǰ��С������������С�ĵ�
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
            if (!visit[j] && dist[j]>graph[index][j])      //ִ�и��£��������뵱ǰ��ľ���������͸���dist
            {
                dist[j] = graph[index][j];
            }
        }
    }
    cout << endl;
    return sum;               //������С����������·��ֵ
}
int main()
{
    cout << prim(0) << endl;//�Ӷ���a��ʼ
    return 0;
}

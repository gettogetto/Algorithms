#include<iostream>
#define N 7
using namespace std;
typedef struct _node{
    int val;//��Ȩ 
    int start;
    int end;
}Node;//Node��ʾ�� 
Node V[N];
int cmp(const void *a, const void *b)
{
    return (*(Node *)a).val - (*(Node*)b).val;
}
int edge[N][3] = {  { 0, 1, 3 },
                    { 0, 4, 1 }, 
                    { 1, 2, 5 }, 
                    { 1, 4, 4 },
                    { 2, 3, 2 }, 
                    { 2, 4, 6 }, 
                    { 3, 4, 7} 
                    };
 
int father[N] = { 0, };
int cap[N] = {0,};
 
void make_set()              //��ʼ�����ϣ������еĵ㶼����һ�����ϣ�ÿ�����϶�ֻ�����Լ�
{
    for (int i = 0; i < N; i++)
    {
        father[i] = i;
        cap[i] = 1;
    }
}
 
int find_set(int x)              //�ж�һ���������ĸ����ϣ�����������Ź�ͬ�����Ƚ�㣬�Ϳ���˵��������һ������
{
    if (x != father[x])
     {                              
        father[x] = find_set(father[x]);
    }     
    return father[x];
}                                  
 
void Union(int x, int y)         //��x,y�ϲ���ͬһ������
{
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return;
    if (cap[x] < cap[y])
        father[x] = find_set(y);
    else
    {
        if (cap[x] == cap[y])
            cap[x]++;
        father[y] = find_set(x);
    }
}
 
int Kruskal(int n)
{
    int sum = 0;
    make_set();
    for (int i = 0; i < N; i++)//���ߵ�˳�򰴴�С����ȡ����
    {
        if (find_set(V[i].start) != find_set(V[i].end))     //����ı���������㻹����һ�������У��Ͳ���һ��������������ĳ��ȼ��������ߵĳ���
        {
            Union(V[i].start, V[i].end);  //�ϲ��������㵽һ������
            sum += V[i].val;
        }
    }
    return sum;
}
int main()
{
    for (int i = 0; i < N; i++)   //��ʼ���ߵ����ݣ���ʵ��Ӧ���пɸ��ݾ������ת�����Ҷ�ȡ����,���ֻ�ǲ�������
    {
        V[i].start = edge[i][0];
        V[i].end = edge[i][1];
        V[i].val = edge[i][2];
    }
    qsort(V, N, sizeof(V[0]), cmp);
    cout << Kruskal(0)<<endl; 
}

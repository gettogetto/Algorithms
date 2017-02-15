/*
С����С��ȥ����ʯ�����Ǵ�һ����ʯ�������ȡ���Ų��Ƚ����ǵ���������Щ��ʯ������������ͬ���������ǱȽ���һ��ʱ������ǿ�����������ʯg1��g2�������������֮ǰ�Ƚϵ���Ϣ�ж���������ʯ���ĿŸ��ء�
����������ʯ�ı��g1,g2����Ŵ�1��ʼ��ͬʱ������ϵ����vector,����Ԫ��ΪһЩ��Ԫ�飬��һ��Ԫ��Ϊһ�αȽ��н��ص���ʯ�ı�ţ��ڶ���Ԫ��Ϊ�������ʯ�ı�š�������֮ǰ�ıȽϴ���n���뷵����������ʯ�Ĺ�ϵ����g1���ط���1��g2���ط���-1���޷��жϷ���0���������ݱ�֤�Ϸ���������ì��������֡�
����������
2,3,[[1,2],[2,4],[1,3],[4,3]],4
����: 1
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
1>2
2>4
1>3
4>3
Ҫ�ж�2��3�Ĺ�ϵ
�����2��ʼ�ܱ�����3����ô2>3,��֮2<3
����ͼ�Ĺ�����ȱ���
1 ����һ����ϣ������Ԫ����Ϊkey������Ԫ����Ϊvalue��vector<int>�ṹ��
2 ��g1��ʼ������ȱ�����ֱ��������g2����g1>g2��������g2��ʼ������ȱ�����ֱ��������g1����g1<g2;�������������޷��ж�
2.1 ����g1�����Ķ��㣨��g1��Ϊkey��Ӧ��value�����������
2.2 ��һ����ϣ���Ǳ��������key�Ƕ��㣬value��bool���ͣ�����Ƿ������
*/

class Cmp {
    bool compare(int g1, int g2, unordered_map<int, vector<int>> graph)
    {
        queue<int> que;
        que.push(g1);
        unordered_map<int, int> flag;
        int temp;
        while (!que.empty())
        {
            temp = que.front();
            flag[temp] = 1;
            que.pop();
            if (temp == g2)
                return true;
            else
            {
                for (int i = 0;i < graph[temp].size();i++)
                {
                    if (!flag[graph[temp][i]])//���graph[temp][i]û�б�������
                        que.push(graph[temp][i]);
                }
            }
        }
        return false;
    }
public:
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
        // write code here
        unordered_map<int, vector<int>> graph;
        for (int i = 0;i < n;i++)
            graph[records[i][0]].push_back(records[i][1]);    
        if (compare(g1, g2, graph))
            return 1;
        else
        {
            if (compare(g2, g1, graph))
                return -1;
            else
                return 0;        
        }
    }
};



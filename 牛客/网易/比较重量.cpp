/*
小明陪小红去看钻石，他们从一堆钻石中随机抽取两颗并比较她们的重量。这些钻石的重量各不相同。在他们们比较了一段时间后，它们看中了两颗钻石g1和g2。现在请你根据之前比较的信息判断这两颗钻石的哪颗更重。
给定两颗钻石的编号g1,g2，编号从1开始，同时给定关系数组vector,其中元素为一些二元组，第一个元素为一次比较中较重的钻石的编号，第二个元素为较轻的钻石的编号。最后给定之前的比较次数n。请返回这两颗钻石的关系，若g1更重返回1，g2更重返回-1，无法判断返回0。输入数据保证合法，不会有矛盾情况出现。
测试样例：
2,3,[[1,2],[2,4],[1,3],[4,3]],4
返回: 1
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
要判断2和3的关系
如果从2开始能遍历到3，那么2>3,反之2<3
类似图的广度优先遍历
1 建立一个哈希表，把左元素作为key，把右元素作为value（vector<int>结构）
2 以g1开始广度优先遍历，直到遍历到g2，则g1>g2；否则以g2开始广度优先遍历，直到遍历到g1，则g1<g2;否则条件不足无法判断
2.1 把与g1相连的顶点（即g1作为key对应的value）依次入队列
2.2 用一个哈希表标记遍历情况，key是顶点，value（bool类型）标记是否遍历过
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
                    if (!flag[graph[temp][i]])//如果graph[temp][i]没有被遍历过
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



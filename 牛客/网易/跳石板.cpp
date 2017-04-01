/*
 跳石板
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前
跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想
跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1

输入例子:
4 24

输出例子:
5
*/
#include<bits/stdc++.h>

using namespace std;
void GetYueShu(int n, vector<int> &yueshu)//求除了1和本身的约数
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            yueshu.push_back(i);
            if (n / i != i)//非平方数时还有另一个数也要加入
                yueshu.push_back(n/i);
        }
    }
}


int Jump(int N, int M)
{
    vector<int> res(M + 1, 0);//储存的到达此res点的步数，初始N为1步
    res[N] = 1;

    for (int i = N; i < M; i++)
    {
        vector<int> yueshu;//N的所有约数，即为从本身这个点开始能走的数量

        if (res[i] == 0)
            continue;//0代表这个点不能到

        GetYueShu(i, yueshu);//求出所有能走的步数储存在yueshu的容器中

        for (auto j = 0; j < yueshu.size(); j++)
        {
            //由位置i出发能到达的点为 res[yueshu[j]+i]
            if ((yueshu[j] + i) <= M&&res[yueshu[j] + i] != 0)
                res[yueshu[j] + i] = min(res[yueshu[j] + i], res[i] + 1);
            else if ((yueshu[j] + i) <= M)
                res[yueshu[j] + i] = res[i] + 1;
        }
    }

    if (res[M] == 0)
        return -1;
    else
        return res[M] - 1;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<Jump(n,m);
}

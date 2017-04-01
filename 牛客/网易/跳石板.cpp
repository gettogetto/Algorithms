/*
 ��ʯ��
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ
��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬����
�������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
��������:
����Ϊһ�У�����������N��M���Կո������
(4 �� N �� 100000)
(N �� M �� 100000)


�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1

��������:
4 24

�������:
5
*/
#include<bits/stdc++.h>

using namespace std;
void GetYueShu(int n, vector<int> &yueshu)//�����1�ͱ����Լ��
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            yueshu.push_back(i);
            if (n / i != i)//��ƽ����ʱ������һ����ҲҪ����
                yueshu.push_back(n/i);
        }
    }
}


int Jump(int N, int M)
{
    vector<int> res(M + 1, 0);//����ĵ����res��Ĳ�������ʼNΪ1��
    res[N] = 1;

    for (int i = N; i < M; i++)
    {
        vector<int> yueshu;//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����

        if (res[i] == 0)
            continue;//0��������㲻�ܵ�

        GetYueShu(i, yueshu);//����������ߵĲ���������yueshu��������

        for (auto j = 0; j < yueshu.size(); j++)
        {
            //��λ��i�����ܵ���ĵ�Ϊ res[yueshu[j]+i]
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

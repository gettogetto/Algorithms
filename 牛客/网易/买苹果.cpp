/*
С��ȥ�������̵���ƻ������թ���̷�ʹ���������ף�ֻ�ṩ6��ÿ����8��ÿ���İ�װ(��װ���ɲ��)�� ����С������ֻ�빺��ǡ��n��ƻ����С���빺�����ٵĴ�������Я����������ܹ���ǡ��n��ƻ����С�׽����Ṻ��
��������:
����һ������n����ʾС���빺��n(1 �� n �� 100)��ƻ��


�������:
���һ��������ʾ������Ҫ����Ĵ��������������ǡ��n��ƻ�������-1

��������:
20

�������:
3
*/
#include<iostream>
using namespace std;
int count(int n){
        if(n%2!=0||n==10||n<6) return -1;//һ����ż����6��8���ǣ�,��С��6��10����ż�������ԣ�
        if(n%8==0) return n/8;//����ð˸��������
        return 1+n/8;//����10���ϵ�ż����ֻҪ��8ȡ������Ϊ0����Ҫ��ǰ���1����2��8���ó�2������������Ϊ6��������������6���Ͳ����ã�������+1��
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}
/*
#include<bits/stdc++.h>
using namespace std;


//ͳ��ƻ��
int CountBags(int N)
{
    int i;
    int minBag=N;//��С�Ĵ���

    if (N&1)
        return -1;

    for (i = 0; i <= N / 6; i++)
    {
        if ((N - 6*i) % 8 == 0)
        {
            int j = (N - 6 * i) / 8;
            minBag = min(i+j,minBag);
        }
    }

    if (minBag != N)
        return minBag;
    else
        return -1;
}
int main(){
    int n;
    cin>>n;
    cout<<CountBags(n);
}
8/

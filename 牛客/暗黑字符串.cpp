/*
һ��ֻ����'A'��'B'��'C'���ַ������������ĳһ�γ���Ϊ3�������Ӵ���ǡ��'A'��'B'��'C'����һ������ô����ַ������Ǵ����ģ���������ַ������ǰ��ڵġ����磺
BAACAACCBAAA �����Ӵ�"CBA"�а�����'A','B','C'��һ���������Ǵ������ַ���
AABBCCAABB ������һ������Ϊ3�������Ӵ�����'A','B','C',�����ǰ��ڵ��ַ���
���������Ǽ��������Ϊn���ַ���(ֻ����'A'��'B'��'C')���ж��ٸ��ǰ��ڵ��ַ����� 
��������:
����һ������n����ʾ�ַ�������(1 �� n �� 30)


�������:
���һ��������ʾ�ж��ٸ������ַ���

��������:
2
3

�������:
9
21
*/

#include<iostream>
#include<vector>
using namespace std;

long solution(int len)
{
	vector<long> last2diff(len+1);
	vector<long> last2same(len+1);
	last2diff[2]=6;
	last2same[2]=3;
	
	for(int i=3;i<=len;i++)
	{
		last2diff[i]=last2diff[i-1]+last2same[i-1]*2;
		last2same[i]=last2diff[i-1]+last2same[i-1];
	}
	
	return last2diff[len]+last2same[len];
	
}

int main()
{
	int len;
	while(cin>>len){
		cout<<solution(len)<<endl;
	}
	return 0;
}

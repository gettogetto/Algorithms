/*
一个只包含'A'、'B'和'C'的字符串，如果存在某一段长度为3的连续子串中恰好'A'、'B'和'C'各有一个，那么这个字符串就是纯净的，否则这个字符串就是暗黑的。例如：
BAACAACCBAAA 连续子串"CBA"中包含了'A','B','C'各一个，所以是纯净的字符串
AABBCCAABB 不存在一个长度为3的连续子串包含'A','B','C',所以是暗黑的字符串
你的任务就是计算出长度为n的字符串(只包含'A'、'B'和'C')，有多少个是暗黑的字符串。 
输入描述:
输入一个整数n，表示字符串长度(1 ≤ n ≤ 30)


输出描述:
输出一个整数表示有多少个暗黑字符串

输入例子:
2
3

输出例子:
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

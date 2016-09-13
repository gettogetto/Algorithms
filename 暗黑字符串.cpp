//暗黑字符串
// 若字符串str中出现连续3个字符为abc的组合，则成为干净字符串；否则为暗黑字符串，问长度为n的字符串中有几个是暗黑字符串。
//例如n=2,返回9，n=3，返回21. 

#include<iostream>
#include<vector>
using namespace std;

int solution(int len)
{
	vector<int> last2diff(len+1);
	vector<int> last2same(len+1);
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

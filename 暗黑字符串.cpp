//�����ַ���
// ���ַ���str�г�������3���ַ�Ϊabc����ϣ����Ϊ�ɾ��ַ���������Ϊ�����ַ������ʳ���Ϊn���ַ������м����ǰ����ַ�����
//����n=2,����9��n=3������21. 

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

/*
��Ŀ��
����һ������n���г� [0,n) ���������ÿ�����ֵĶ����ư������ٸ�1.
���磺
����5
0, 1, 2, 3, 4
����1�ĸ����ֱ���
0, 1, 1, 2, 1

�ö�̬�滮��n����0ʱ��1�ĸ�����0��n���ڵ���2��Ϊ������f(n)=f(n-1)+1��n���ڵ���2��Ϊż����f(n)=f(n/2)
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> solution(int n){
	vector<int>count(n,0);
	count[1]=1;
	for(int i=2;i<n;i++){
		if(i&1) count[i]=count[i-1]+1;
		else count[i]=count[i/2];
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> count=solution(n);
	for(auto i:count) cout<<i<<" ";
	
}

//��1-n���Եĵ������Լ���ĺ� 
#include<iostream>

#include<vector>
using namespace std;
int maxOdd(int n)
{
	if(n==0) return 0;
	if(n&1) return ((n+1)/2)*((n+1)/2)+maxOdd((n-1)/2);
	else{
		return (n/2)*(n/2)+(maxOdd(n/2));
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<maxOdd(n);
	
}

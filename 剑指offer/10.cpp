#include<iostream>
using namespace std;
int numberOf1(int n){
	unsigned int flag=1;//����n��λ����ΪnΪ����ʱ����λ������λ��������ѭ�������Լ���һ���޷������������ư�λ�� 
	int count=0;
	while(flag){
		if(n&flag) count++;
		flag<<=1;
	}
	return count;
}
int numberOf1_2(int n){
	int count=0;
	while(n){
		n=n&(n-1);//n&(n-1)���n�����ұߵ�1��0 
		count++;
	}
	return count;
}
int main(){
	int n;
	cin>>hex>>n;
	cout<<dec<<n; 
}

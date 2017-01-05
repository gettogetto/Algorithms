#include<iostream>
using namespace std;
int numberOf1(int n){
	unsigned int flag=1;//不对n移位，因为n为负数时，高位补符号位，导致死循环，所以加入一个无符号整型来左移按位与 
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
		n=n&(n-1);//n&(n-1)会把n的最右边的1置0 
		count++;
	}
	return count;
}
int main(){
	int n;
	cin>>hex>>n;
	cout<<dec<<n; 
}

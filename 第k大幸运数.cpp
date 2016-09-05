//求第k大的幸运数
//只含有4，7的数称为幸运数 
//4 7 
//44 47 74 77 
//444 447 474 477 744 747 774 777
//4444，... 
#include<iostream> 
#include<string>
#include<vector>
#include<cmath>
#include<bitset>
using namespace std;
int getBits(long,long&);
string helper(int);
int main()
{
	int k=1000000000;
	cout<<helper(k);
	
}

//功能：求第k大的幸运数的位数bits，以及位数 1~bits-1之前的幸运数总量 ，preSum指的是位数 1~bits-1 幸运数总和 
int getBits(long k,long& preSum){
	long sum=0;
	int bits=0;
	while(sum<k){
		preSum=sum;
		sum+=pow(2,++bits);
	}
	return bits;
}
//求第k大幸运数，用string表示 
string helper(int k)
{
	long preSum;
	int bits=getBits(k,preSum);
	int kth=k-preSum;//表示第k大幸运数，在位数为bits的幸运数中排在第几个 
	
	//把4，7看作0，1 
	string res(bits,'4');
	kth--;
	while(bits){
		if(kth&1) res[bits-1]='7';
		else res[bits-1]='4';
		bits--;
		kth>>=1;
	}
	/*
	string res;
	bitset<100> bs(kth-1);
	for(int i=0;i<bits;i++){
		if(bs[bits-i-1]==1) res+='7';
		else res+='4';
	}*/
	return res;
	
}

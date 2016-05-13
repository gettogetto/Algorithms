#include<iostream>
using namespace std;

void hanoi(int n,char a,char b,char c) {
	if(n==1)
		cout<<n<<" "<<a<<" "<<c<<endl;//n号盘子从a移到c 
	else {
		hanoi(n-1,a,c,b);
		cout<<n<<" "<<a<<" "<<c<<endl;
		hanoi(n-1,b,a,c);
	}
}

int main() {
	int n;
	cout<<"输入正整数:"<<endl;
	cin>>n;
	cout<<"结果为"<<endl;
	hanoi(n,'A','B','C');
	return 0;
}

#include<iostream>
using namespace std;

void hanoi(int n,char a,char b,char c) {
	if(n==1)
		cout<<n<<" "<<a<<" "<<c<<endl;//n�����Ӵ�a�Ƶ�c 
	else {
		hanoi(n-1,a,c,b);
		cout<<n<<" "<<a<<" "<<c<<endl;
		hanoi(n-1,b,a,c);
	}
}

int main() {
	int n;
	cout<<"����������:"<<endl;
	cin>>n;
	cout<<"���Ϊ"<<endl;
	hanoi(n,'A','B','C');
	return 0;
}

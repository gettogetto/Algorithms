#include<iostream>
#include<vector>
using namespace std;
//n�߳� ��time�ڼ��������ߣ�startval��ʼֵ��output���ɵľ���
void func(int n,int time,int startval,vector<vector<int> >&output){
	if(time>(n+1)/2) return;//���귵��
	for(int col=time-1;col<=n-time;col++){//����
		output[time-1][col]=startval++;
	}
	for(int row=time;row<=n-time;row++){//����
		output[row][n-time]=startval++;
	}
	for(int col=n-time-1;col>=time-1;col--){//����
		output[n-time][col]=startval++;
	}
	for(int row=n-time-1;row>=time;row--){//����
		output[row][time-1]=startval++;
	}
	func(n,time+1,startval,output);//��һ��������
}
int main(){
	int n;
	while(cin>>n){
		vector<vector<int> >out(n,vector<int>(n,0));
		func(n,1,1,out);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<out[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

#include<iostream>
#include<vector>
using namespace std;
//n边长 ，time第几次向右走，startval起始值，output生成的矩阵
void func(int n,int time,int startval,vector<vector<int> >&output){
	if(time>(n+1)/2) return;//走完返回
	for(int col=time-1;col<=n-time;col++){//向右
		output[time-1][col]=startval++;
	}
	for(int row=time;row<=n-time;row++){//向下
		output[row][n-time]=startval++;
	}
	for(int col=n-time-1;col>=time-1;col--){//向左
		output[n-time][col]=startval++;
	}
	for(int row=n-time-1;row>=time;row--){//向上
		output[row][time-1]=startval++;
	}
	func(n,time+1,startval,output);//下一次向右走
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

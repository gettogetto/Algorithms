//n个骰子，求和等于target的所有情况 
#include<vector>
#include<iostream>
using namespace std;

void helper(int n,int cursum,int target,vector<int>& save){
	if(n==0){
		if(cursum==target){		
			for(auto i:save) cout<<i<<" ";
			cout<<endl;
		}
		return;
	}
	
	for(int num=1;num<=6;num++){
		save.push_back(num);
		helper(n-1,cursum+num,target,save);
		save.pop_back();
	}
}
void solution1(int n,int target){
	vector<int> v;
	helper(n,0,target,v);
}

int main(){
	int n;
	cin>>n;
	int target;
	cin>>target;
	solution1(n,target);
}

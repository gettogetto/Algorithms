#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//法一，快速选择 
void findKMostSmall(vector<int>& nums,int k){
	int L=0,R=nums.size()-1;
	while(L<R){
		int left=L,right=R;
		int key=nums[left];
		while(left<right){
			
			while(left<right&&nums[right]>=key) right--;
			nums[left]=nums[right];
			while(left<right&&nums[left]<=key) left++;
			nums[right]=nums[left];
			
		}
		nums[left]=key;
		if(left==k-1) return;
		else if(left>k-1){
			R=right-1;
		}else{
			L=left+1;
		}
	}
}
//法二使用最大堆 
struct compare{
	bool operator()(int a,int b){
		return a<=b;//最大堆 
	}
}; 

vector<int> findKMostSmall2(const vector<int>&nums,int k){
	priority_queue<int,vector<int>,compare> pq;
	int i=0;
	for(i=0;i<k;i++) pq.push(nums[i]);
	for(;i<nums.size();i++){
		if(pq.top()>nums[i]){
			pq.pop();
			pq.push(nums[i]);
		}
	}
	vector<int> v;
	while(pq.size()){
		v.push_back(pq.top());
		pq.pop();
	} 
	return v;
}



int main(){
	//法一 
	vector<int> v={6,6,5,5,4,4,3,3,2,2,1,1};
	findKMostSmall(v,3);
	for(int i=0;i<3;i++) cout<<v[i]<<" ";
	cout<<endl;
	//法二 
	vector<int> v2={6,6,5,5,4,4,3,3,2,2,1,1};
	vector<int> res=findKMostSmall2(v2,3);
	for(auto i:res) cout<<i<<" ";
	cout<<endl;
}

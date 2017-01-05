#include<iostream>
#include<vector>
using namespace std;
bool isOdd(int n){
	return n&1;
}
void oddEven(vector<int>& nums,int left,int right,bool (*func)(int)){
	if(left>=right) return;
	int low=left,high=right;
	int key=nums[left];
	while(low<high){
		while(low<high&&!func(nums[high])) high--;
		nums[low]=nums[high];
		while(low<high&&func(nums[low])) low++;
		nums[high]=nums[low];		
	}
	nums[low]=key;
	oddEven(nums,left,low-1,func);
	oddEven(nums,low+1,right,func);
}
int main(){
	vector<int>nums={1,2,3,4,5,6,7,8,9};
	oddEven(nums,0,nums.size()-1,isOdd);
	for(auto n:nums) cout<<n<<" ";
}

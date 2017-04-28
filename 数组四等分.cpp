#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(vector<int>& nums){
	int left=1,right=nums.size()-2,mid=left+2;	
	int sum1=nums[0],
	sum2=accumulate(nums.begin()+left+1,nums.begin()+mid,0),
	sum3=accumulate(nums.begin()+mid+1,nums.begin()+right,0),
	sum4=nums.back();
	while(left<right){
		if(sum1<sum4){
			sum1+=nums[left];
			sum2-=nums[left];
			left++;
			if(left+1==mid){
				mid=left+2;	
			//	sum1+=nums[mid-1];
				sum2=nums[left+1];
				sum3-=nums[mid];
			}
		}else if(sum1>sum4){
			sum4+=nums[right];
			sum3-=nums[right];
			right--;
		}else{
			//mid=max(left+2,mid);
			//sum2=accumulate(nums.begin()+left+1,nums.begin()+mid,0);
			//sum3=accumulate(nums.begin()+mid+1,nums.begin()+right,0);
			while(sum2<sum1){
				sum2+=nums[mid];
				sum3-=nums[mid];
				mid++;
			}
			if(sum2==sum1&&sum2==sum3) return true;
			left++,right--;
		}
	}
	return false;
	
}
int main(){
	vector<int> nums={2,5,1,1,1,1,4,1,7,3,7};///{10,2,11,13,1,1,1,1,1};//
	cout<<solve(nums);
}

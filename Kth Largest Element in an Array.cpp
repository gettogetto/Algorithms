    #include<iostream>
    #include<vector>
    using namespace std;
	int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int L=0,R=n-1;
        while(L<R){
        	int left=L,right=R;
        	int key=nums[left];
        	while(left<right){
        		while(left<right&&nums[right]<=key) right--;
        		nums[left]=nums[right];
        		while(left<right&&nums[left]>=key) left++;
        		nums[right]=nums[left];
			}
			nums[left]=key;
			if(left+1==k) return nums[left];
			else if(left+1>k){
				R=left-1;
			}else{
				L=left+1;
			}
		}
		return nums[k-1];
    }
    int main(){
    	vector<int>nums={4,4,4,4,4,3,2,1};
    	cout<<findKthLargest(nums,4);
	}

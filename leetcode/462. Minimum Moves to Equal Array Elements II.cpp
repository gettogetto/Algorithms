/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int k=nums.size()/2+1;
        int kthsmall=findKth(nums,0,nums.size()-1,k);
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=abs(nums[i]-kthsmall);
        }
        return res;
    }
    int findKth(vector<int>& nums,int left,int right,int k){
        int Left=0,Right=nums.size()-1;
        while(Left<Right){
            left=Left,right=Right;
            int privot=nums[Left];
            while(left<right){
                while(left<right&&nums[right]>=privot) right--;
                nums[left]=nums[right];
                while(left<right&&nums[left]<=privot) left++;
                nums[right]=nums[left];
            }
            nums[left]=privot;
            if(left+1==k) return nums[left];
            else if(left+1>k) Right=left-1;
            else Left=left+1;
        }
        return nums[Left];
    }
};


//ÀûÓÃstlµÄnth_element
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto it = nums.begin() + nums.size()/2;
        nth_element(nums.begin(), it, nums.end());
        int kthsmall = *it;
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=abs(nums[i]-kthsmall);
        }
        return res;
    }
}; 

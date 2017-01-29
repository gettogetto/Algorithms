/*
Given an array of integers, 1 �� a[i] �� n (n = size of array), some elements appear twice and others appear once.


Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();){
            if(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) res.push_back(nums[i]);
        }
       // unique(res.begin(),res.end());
        return res;
    }
};

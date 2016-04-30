/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int posmax=nums[0];
        int negmax=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            int postmp=posmax;
            int negtmp=negmax;
            
            posmax=max(nums[i],max(nums[i]*postmp,nums[i]*negtmp));
            negmax=min(nums[i],min(nums[i]*postmp,nums[i]*negtmp));
            
            res=max(res,posmax);
        }
        return res;
    }
};

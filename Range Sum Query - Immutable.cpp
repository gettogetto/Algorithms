/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
class NumArray {
private:
    vector<int>v;    
public:
    NumArray(vector<int> &nums) {
        int n=nums.size();
        if(n==0) return;
        v.reserve(n);
        v[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=nums[i]+v[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i>j) return 0;
        return v[j]-v[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

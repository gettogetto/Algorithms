/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

// O(n) solution

class Solution {
public:
    int maxSubArray(vector<int>&A) {
        int res = A[0], tmp = A[0];
        for (int i = 1; i < A.size(); ++i) {
            tmp = max(tmp + A[i], A[i]);
            res = max(res, tmp);
        }
        return res;
    }
};


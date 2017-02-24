/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/
class Solution {
public:
//1-32位，对每位二进制数都遍历数组中的元素。统计含1的与含0的数目，分别为k和n-k，其中n为数组元素个数。则此位贡献 k(n-k)的汉明距离 
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            int have1=0;
            for(int j=0;j<n;j++){
                have1+=(nums[j]>>i)&1;
            }
            res+=have1*(n-have1);
        }
        return res;
    }
};

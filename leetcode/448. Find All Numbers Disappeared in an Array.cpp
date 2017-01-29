/*
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();){
            if(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) res.push_back(i+1);
        }
        return res;
    }
};


//method 2
/*
The basic idea is that we iterate through the input array and mark elements as negative 
using nums[nums[i] -1] = -nums[nums[i]-1]. In this way all the numbers that we have seen will be marked as negative. 
In the second iteration, if a value is not marked as negative, it implies we have never seen that index before, so just add it to the return list.
*/ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int val=abs(nums[i])-1;
            if(nums[val]>0){
                nums[val]=-nums[val];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};

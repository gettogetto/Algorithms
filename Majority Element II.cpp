/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int a1=0,a2=1,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a1==nums[i]) c1++;
            else if(a2==nums[i]) c2++;
            else if(c1==0) a1=nums[i],c1++;
            else if(c2==0) a2=nums[i],c2++;
            else c1--,c2--;
        }
        vector<int> res;
        c1=c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a1) c1++;
            else if(nums[i]==a2) c2++;
        }
        if(c1>n/3) res.push_back(a1);
        if(c2>n/3) res.push_back(a2);
        return res;
    }
};

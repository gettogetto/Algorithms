/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/
/*
The key concept here is: Given a set of integers that satisfies the property that each pair of integers 
inside the set are mutually divisible, for a new integer S, 
S can be placed into the set as long as it can divide the smallest number of the set or 
is divisible by the largest number of the set.

For example, let's say we have a set P = { 4, 8, 16 }, 
P satisfies the divisible condition. Now consider a new number 2, 
it can divide the smallest number 4, so it can be placed into the set; similarly, 
32 can be divided by 16, the biggest number in P, it can also placed into P.

Next, let's define:

For an increasingly sorted array of integers a[1 .. n]

T[n] = the length of the largest divisible subset whose largest number is a[n]

T[n+1] = max{ 1 + T[i] if a[n+1] mod a[i] == 0 else 1 }

Now, deducting T[n] becomes straight forward with a DP trick. For the final result we will need to maintain a backtrace array for the answer.
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>count(n,0);
        vector<int>parent(n,0);
        int maxCount=0;
        int minIndex=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(nums[j]%nums[i]==0&&count[i]<count[j]+1){
                    count[i]=count[j]+1;
                    parent[i]=j;
                    if(count[i]>maxCount){
                        maxCount=count[i];
                        minIndex=i;
                    }
                }
            }
        }
        vector<int>res;

        for(int i=0;i<maxCount;i++){
            
            res.push_back(nums[minIndex]);
            minIndex=parent[minIndex];
        }
        return res;
        
    }
};

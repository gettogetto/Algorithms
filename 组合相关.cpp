
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        v.resize(k);
        dfs(1, n, k);
        return r;
    }
private:
    vector<vector<int> > r;
    vector<int> v;
    void dfs(int i, int n, int k) {
        while (i <= n) {
            v[v.size() - k] = i++;
            if (k > 1)
                dfs(i, n, k - 1);
            else
                r.push_back(v);
        }
    }
};

/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
class Solution {
public:
    vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<std::vector<int> > res;
        vector<int> tmp;
        combinationSum(candidates,tmp,res,target, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates,vector<int> &tmp, vector<vector<int> > &res,int target, int begin) {
        if  (!target) {
            res.push_back(tmp);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            tmp.push_back(candidates[i]);
            combinationSum(candidates, tmp, res, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};


/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};



/*
Find all possible combinations of k numbers that add up to a number n, given that only 
numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]*/


class Solution {
public:
#define maxval (9) 
    void helper(int k,int n,int curval,vector<int>&tmp,vector<vector<int>>& res){
		if(k<0) return;
        if(k==0&&n==0){
            res.push_back(tmp);
            return;
        }
        for(int val=curval;val<=maxval;val++){
            tmp.push_back(val);
            helper(k-1,n-val,val+1,tmp,res);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>tmp;
        vector<vector<int>> res;
        helper(k,n,1,tmp,res);
        return res;
        
    }
};


/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<dp.size();i++){
            for(auto num:nums){
                if(num<=i){
                    dp[i]+=dp[i-num];
                }
            }
        }
        return dp[target];
    }

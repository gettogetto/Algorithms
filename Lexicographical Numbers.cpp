/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/
//法一 dfs 
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        dfs(res,n,1);
        return res;
    }
    void dfs(vector<int>&res,int n,int now){
        if(now>n) return;
        res.push_back(now);
        dfs(res,n,now*10);
        if(now%10<9){
            dfs(res,n,now+1);
        }
    }
};
//法二 dp
class Solution {
public:
     vector<int> lexicalOrder(int n) {
        vector<int> res(n,1);
        for(int i=1;i<n;i++)
        {
            int pre=res[i-1];
            if(pre*10<=n){
                res[i]=pre*10;
            }else{
                while(pre+1>n || pre%10==9) pre/=10;
                
                res[i]=pre+1;
            }
        }
        return res;
    }
    
};
 


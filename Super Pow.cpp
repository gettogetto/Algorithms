/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
*/
class Solution {
public:
    long long  myPow(long long x, int n) {
        long long ans = 1;
        long long absN = abs((long long)n);
        while(absN > 0) {
            if((absN&1)==1) ans=ans*x%1337;
            absN >>= 1;
            x =x*x%1337;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int size=b.size();
        long long res=1;

        for(int i=0;i<size;i++){
        
            res=myPow(res,10)*myPow(a,b[i])%1337;
        }
        return res;
    }
    
};

/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the 
sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
*/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size=primes.size();
        if(n<0) return 0;
        if(n==1) return 1;
        vector<int>k(n);
        k[0]=1;
        vector<int>t(size,0);
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
            for(int index=0;index<size;index++){
                mini=min(mini,k[t[index]]*primes[index]);
            }
            k[i]=mini;
            for(int index=0;index<size;index++){
                if(k[t[index]]*primes[index]==k[i]) t[index]++;
            }
            
        }
        return k[n-1];
    }
};


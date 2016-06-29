/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/
class Solution {
public:
    int mySqrt1(int x) {//newton
        long long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }

    int mySqrt2(int x) {//binary search
        if(x <= 1) return x;
        int left = 1, right = x;
        while(left <right) {
            int mid = left + (right - left) / 2;
            if(mid <= x / mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left-1 ;
    }
    bool isPerfectSquare(int num) {
        int sqrtres=mySqrt1(num);
        return sqrtres*sqrtres==num;
    }
};

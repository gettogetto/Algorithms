/*
Let's get started. We subtract 3 from 15 and we get 12, which is positive. 
Let's try to subtract more. Well, we shift 3 to the left by 1 bit and we get 6. 
Subtracting 6 from 15 still gives a positive result. Well, we shift again and get 12. 
We subtract 12 from 15 and it is still positive. We shift again, obtaining 24 and we know we can at most subtract 12. 
Well, since 12 is obtained by shifting 3 to left twice, we know it is 4 times of 3. 
How do we obtain this 4? Well, we start from 1 and shift it to left twice at the same time. 
We add 4 to an answer (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3. 
We now get part of the quotient (4), with a remainder 3.

Then we repeat the above process again. We subtract divisor = 3 from the remaining dividend = 3 and obtain 0. 
We know we are done. No shift happens, so we simply add 1 << 0 to the answer.
*/
    #include<iostream>
    #include<algorithm>
    using namespace std;
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
    int main(){
        cout<< divide(100,3);
    }

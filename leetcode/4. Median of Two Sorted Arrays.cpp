/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b,n,a,m,k);
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        int j = min(n,k/2);
        int i = k-j;
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m+n)/2;
        int m1 = kth(a,m,b,n,k+1);
        if ((m+n)%2==0) {
            int m2 = kth(a,m,b,n,k);
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }
};

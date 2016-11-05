class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) < 3 :
            return 0
        l = [0]*len(A)
        if A[2]-A[1] == A[1]-A[0]:
            l[2] = 1
        res = l[2]
        for i in range(3,len(A)):
            if A[i]-A[i-1] == A[i-1]-A[i-2]:
                l[i]=l[i-1]+1
            res += l[i]
        return res
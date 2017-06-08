# Time:  O(k * n)
# Space: O(k)
#
# Say you have an array for which the ith element is the price of a given stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete at most k transactions.
# 
# Note:
# You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
#

class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        n=len(prices)
        if n<2:return 0
        res=0
        if k>n/2:
            for i in xrange(0,n-1):
                res+=max(0,prices[i+1]-prices[i])
            return res

        buy,sell=[float('-inf')]*n,[0]*n
        for i in xrange(0,n):
            buy[0]=max(buy[0],-prices[i])
            sell[0]=max(sell[0],buy[0]+prices[i])
            for j in xrange(1,k):
                buy[j]=max(buy[j],sell[j-1]-prices[i])
                sell[j]=max(sell[j],buy[j]+prices[i])
        return sell[k-1]

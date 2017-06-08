# Time:  O(n)
# Space: O(1)
#
# Say you have an array for which the ith element 
# is the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. 
# You may complete at most two transactions.
#
# Note:
# You may not engage in multiple transactions at the same time 
# (ie, you must sell the stock before you buy again).
#

# Time:  O(n)
# Space: O(1)
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy1,sell1,buy2,sell2=float('-inf'),0,float('-inf'),0
        for i in xrange(len(prices)):
            buy1=max(buy1,-prices[i])
            sell1=max(sell1,buy1+prices[i])
            buy2=max(buy2,sell1-prices[i])
            sell2=max(sell2,buy2+prices[i])
        return sell2
    

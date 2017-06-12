# Time:  O(m * n)
# Space: O(m + n)
#
# Follow up for "Unique Paths":
# 
# Now consider if some obstacles are added to the grids. How many unique paths would there be?
# 
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
# 
# For example,
# There is one obstacle in the middle of a 3x3 grid as illustrated below.
# 
# [
#   [0,0,0],
#   [0,1,0],
#   [0,0,0]
# ]
# The total number of unique paths is 2.
# 
# Note: m and n will be at most 100.
#
class Solution1(object):
    def uniquePathsWithObstacles(self, ob):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        r=len(ob)
        c=len(ob[0])
        dp=[[0 for i in xrange(c)] for j in xrange(r)]
        if ob[0][0]==1:
            dp[0][0]=0
        else:
            dp[0][0]=1

        for i in xrange(0,r):
            for j in xrange(0,c):
                if i==0 and j==0:continue
                if i==0:
                    if ob[i][j]==1:
                        dp[i][j]=0
                    else:
                        dp[i][j]=dp[i][j-1]
                elif j==0:
                    if ob[i][j]==1:
                        dp[i][j]=0
                    else:
                        dp[i][j]=dp[i-1][j]
                else:
                    if ob[i][j]==1:
                        dp[i][j]=0
                    else:
                        dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[r-1][c-1]

class Solution2:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        ways = [0] * n
        
        if obstacleGrid[0][0] == 0:
            ways[0] = 1
            
        for j in xrange(1, n):
            if obstacleGrid[0][j] == 1:
                ways[j] = 0
            else:
                ways[j] = ways[j - 1]
        
        for i in xrange(1, m):
            if obstacleGrid[i][0] == 1:
                ways[0] = 0
                
            for j in xrange(1, n):
                if obstacleGrid[i][j] == 1:
                    ways[j] = 0
                else:
                    ways[j] += ways[j - 1]
        
        return ways[n - 1]

if __name__ == "__main__":
    obstacleGrid = [
                      [0,0,0],
                      [0,1,0],
                      [0,0,0]
                   ]
    print Solution().uniquePathsWithObstacles(obstacleGrid)
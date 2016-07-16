/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

/*
思路 
Definition of dp[i][j]: minimum number of money to guarantee win for subproblem [i, j].

Target: dp[1][n]

Corner case: dp[i][i] = 0 (because the only element must be correct)

Equation: we can choose k (i<=k<=j) as our guess, and pay price k.
 After our guess, the problem is divided into two subproblems. 
 Notice we do not need to pay the money for both subproblems.
  We only need to pay the worst case (because the system will tell us which side we should go) to guarantee win.
   So dp[i][j] = min (i<=k<=j) { k + max(dp[i][k-1], dp[k+1][j] }
*/
class Solution {
public:
	//法一 
    int getMoneyAmount(int n) {
        vector<vector<int> >cost(n+2,vector<int>(n+2,0));//下标0和n+1纯粹是为了计算方便而引入的，于是下面guess-1和guess+1无需判断是否越界 
        for(int right=1;right<=n;right++){//cost[left][right] 指闭区间left,right内的花费 
            for(int left=right-1;left>=1;left--){
                int minCostInThisRange=INT_MAX;
                for(int guess=left;guess<=right;guess++){
                    
                    minCostInThisRange=min(minCostInThisRange,guess+max(cost[left][guess-1],cost[guess+1][right]));
                }
                cost[left][right]=minCostInThisRange;
            }
        }
        return cost[1][n];
    }
    
    //法二 
    int getMoneyAmount(int n) {
        vector<vector<int> >cost(n+2,vector<int>(n+2,0));
        for(int diff=1;diff<=n;diff++){
            for(int left=1;left+diff<=n;left++){
                int right=left+diff;
                int minCostInThisRange=INT_MAX;
                for(int guess=left;guess<=right;guess++){
                    minCostInThisRange=min(minCostInThisRange,guess+max(cost[left][guess-1],cost[guess+1][right]));
                }
                cost[left][right]=minCostInThisRange;
            }
        }
        return cost[1][n];
    }
};

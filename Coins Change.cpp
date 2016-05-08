
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//too slow
void helper(vector<int>&coins,int index,int cursum,int amount,int cnt,int& mincnt);
int coinChange1(vector<int>& coins, int amount)
{
    if(amount==0) return 0;
    int cnt=0;
    int mincnt=INT_MAX;
    helper(coins,0,0, amount,cnt,mincnt);
    if(mincnt==INT_MAX) return -1;
    else return mincnt;
}
void helper(vector<int>&coins,int index,int cursum,int amount,int cnt,int& mincnt)
{
    if(cnt>=mincnt) return;
    if(cursum==amount)
    {
        mincnt=min(cnt,mincnt);
        return;
    }
    if(index==coins.size()) return;
    if(cursum>amount) return;

    helper(coins,index+1,cursum,amount,cnt,mincnt);//不加coin[index]，index++

    helper(coins,index,cursum+coins[index],amount,++cnt,mincnt);//加coin[index]，index不变，因为可能继续使用coins[index]


}

//fast o(n*amount)
int coinChange2(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main()
{
    vector<int> coins= {244,125,459,120,316,68,357,320};


    int amount=9793;
    cout<<coinChange2(coins,amount)<<endl;

}

class Solution {
public:
    int ans(int i, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(i>=coins.size())
            return 0;
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        if(amt==0)
            return 1;
        int nottake=ans(i+1,amt,coins,dp);
        int take=0;
        if(amt>=coins[i])
            take=ans(i,amt-coins[i],coins,dp);
        dp[i][amt]=take+nottake;
        return dp[i][amt];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return ans(0,amount,coins,dp);
    }
};

// 2d dp
// row: size of array coins
// col: total amount
// dp[i][j]=ways to make current amount j by using the current coin coin[i]
// for eg: dp[1][3] toral ways to make amount 3 by using current value, ie coins[1]
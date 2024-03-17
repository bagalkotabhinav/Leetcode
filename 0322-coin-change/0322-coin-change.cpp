class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){

        if(amount==0)
            return 0;

        if(amount<0)
            return INT_MAX;

        if(dp[amount]!=-1)
            return dp[amount];

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int x=solve(coins,amount-coins[i],dp);
            if(x!=INT_MAX){
                mini=min(mini,x+1);
            }
        }
        dp[amount]=mini;
        return mini;
    }
    int solve2(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        int mini=INT_MAX;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
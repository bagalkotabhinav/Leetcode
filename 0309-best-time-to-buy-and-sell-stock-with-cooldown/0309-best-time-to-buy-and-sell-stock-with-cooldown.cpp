class Solution {
public:
    int ans(int i,int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy){
            int buy_cur=-prices[i]+ans(i+1,0,prices,dp);
            int hold_cur=0+ans(i+1,1,prices,dp);
            dp[i][buy]=max(buy_cur,hold_cur);
        }
        else{
            int sell_cur=prices[i]+ans(i+2,1,prices,dp);
            int hold_cur=0+ans(i+1,0,prices,dp);
            dp[i][buy]=max(sell_cur,hold_cur);
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,-1));
        return ans(0,1,prices,dp);
    }
};

// 2d dp:
// row: size of prices
// col: buy or not buy
// dp[i][j]=max profit by taking decision j with current current price index i
// ie dp[2][0]=max profit by not buying(sell or hold) thr current coin, prices[2]
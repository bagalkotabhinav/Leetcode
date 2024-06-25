class Solution {
public:
    int ans(int i, vector<int>& prices, vector<vector<int>>& dp, int buy){
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy==1){
            int purch_cur=-prices[i]+ans(i+1,prices,dp,0);
            int skip_cur=0+ans(i+1,prices,dp,1);
            dp[i][buy]=max(purch_cur,skip_cur);
        }
        else{
            int sell_cur=prices[i]+ans(i+2,prices,dp,1);
            int skip_cur=0+ans(i+1,prices,dp,0);
            dp[i][buy]=max(sell_cur,skip_cur);
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int res=ans(0,prices,dp,1);
        return res;
    }
};
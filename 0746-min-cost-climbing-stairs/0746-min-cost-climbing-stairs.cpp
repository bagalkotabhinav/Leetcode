class Solution {
public:
    int ans(vector<int>& cost, int n,vector<int>& dp){
        //BASE CASE
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        //TO REMOVE OVERLAPPING COMPUTATIONS
        if(dp[n]!=-1)
            return dp[n];
        //MEMOISATION: STORING ANSWERS
        dp[n]=cost[n]+min(ans(cost,n-1,dp),ans(cost,n-2,dp));
        return dp[n];
    }
    int ans2(vector<int>& cost, int n){
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n-1;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return(min(dp[n-2],dp[n-1]));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int a=min(ans(cost,n-1,dp),ans(cost,n-2,dp));
        int b=ans2(cost,n);
        return b;
    }
};


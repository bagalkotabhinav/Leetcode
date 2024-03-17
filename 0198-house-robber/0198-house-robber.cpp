class Solution {
public:
    int solve(vector<int>& nums, int i,vector<int>& dp){
        int n=nums.size();
        if(i>n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxi=INT_MIN;
        int p1=nums[i]+solve(nums,i+2,dp);
        int p2=solve(nums,i+1,dp);
        int p3=max(p1,p2);
        maxi=max(maxi,p3);
        dp[i]=maxi;
        return dp[i];
    }

    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int ans=solve(nums,0,dp);
        return ans;
    }
};
class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp){
        int n=nums.size();
        if(i==nums.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        if(i<n-1 && nums[i]==nums[i+1]){
            if(solve(nums,i+2,dp)){
                dp[i]=true;
                return dp[i];
            }
        }
        if(i<n-2 && nums[i]==nums[i+1] and nums[i]==nums[i+2]){
                if(solve(nums,i+3,dp)){
                    dp[i]=true;
                    return dp[i];
                }
            }
        if(i<n-2 && nums[i+1]==nums[i]+1 & nums[i+2]==nums[i]+2){
            if(solve(nums,i+3,dp)){
                dp[i]=true;
                return dp[i];
            }
        }
        dp[i]=false;
        return dp[i];
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};
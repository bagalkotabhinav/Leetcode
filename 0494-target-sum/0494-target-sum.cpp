class Solution {
public:
    int ans(int i, vector<int>& nums, int target, int res, vector<vector<int>>& dp, int sum){
        if(i==nums.size()){
            if(res==target)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum+res]!=-1)
            return dp[i][sum+res];
        dp[i][sum+res]=ans(i+1,nums,target,res+nums[i],dp,sum)+ans(i+1,nums,target,res-nums[i],dp,sum);
        return dp[i][sum+res];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,-1));
        return ans(0,nums,target,0,dp,sum);
    }
};
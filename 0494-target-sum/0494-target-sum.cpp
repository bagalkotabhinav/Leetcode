class Solution {
public:
    int ans(int i, vector<int>& nums, int target, int sum, int total,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(total==target)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum+total]!=-1)
            return dp[i][sum+total];
        dp[i][sum+total]=ans(i+1,nums,target,sum,total+nums[i],dp)+ans(i+1,nums,target,sum,total-nums[i],dp);
        return dp[i][sum+total];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,-1));
        return ans(0,nums,target,sum,0,dp);
    }
};


//if all -ve, then sum will be -sum, and if all +ve, sum will be +um, hence, from -sum to +sum, range of dp is set
// for [1,1,1,1,1]
// [-5,-4,-3,-2,-1,0,1,2,3,4,5], sum=5, range:[-5,5]
// hence, dp[i][total] when current total is 0, it will be at 0, ie index 5,
// hence dp[i][sum+total] is correct to represent 0 total.
// negative numbers will be represented backwards
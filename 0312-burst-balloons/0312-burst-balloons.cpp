class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left,right,cur,res;
        for(int k=i;k<=j;k++){
            left=solve(nums,i,k-1,dp);
            right=solve(nums,k+1,j,dp);
            cur=nums[i-1]*nums[k]*nums[j+1];
            res=max(res,left+right+cur);
        }
        return dp[i][j]=res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,1,nums.size()-2,dp);
    }
};
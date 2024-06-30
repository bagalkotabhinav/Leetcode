class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& matrix, int prev, vector<vector<int>>& dp){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]<=prev)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a=solve(i+1,j,m,n,matrix,matrix[i][j],dp);
        int b=solve(i,j+1,m,n,matrix,matrix[i][j],dp);
        int c=solve(i-1,j,m,n,matrix,matrix[i][j],dp);
        int d=solve(i,j-1,m,n,matrix,matrix[i][j],dp);
        dp[i][j]=1+max({a,b,c,d});
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int res=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,solve(i,j,m,n,matrix,-1,dp));
            }
        }
        return res;
    }
};
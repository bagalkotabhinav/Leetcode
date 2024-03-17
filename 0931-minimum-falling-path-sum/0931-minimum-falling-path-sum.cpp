class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);

        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                if(col==0){
                    dp[row][col]=matrix[row][col]+min(dp[row-1][col],dp[row-1][col+1]);
                }
                else if(col==n-1){
                    dp[row][col]=matrix[row][col]+min(dp[row-1][col],dp[row-1][col-1]);
                }
                else{
                    dp[row][col]=matrix[row][col]+min(dp[row-1][col-1],min(dp[row-1][col],dp[row-1][col+1]));
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
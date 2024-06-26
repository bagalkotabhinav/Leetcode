class Solution {
public:

    bool solve(string &s1, string &s2, string &s3, int i ,int j, int index, vector<vector<int>> &dp){
        if(index==s3.size())
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];

        bool a = false;
        if(s1[i]==s3[index] && i<s1.size()){
            a = solve(s1,s2,s3,i+1,j,index+1,dp);
        }

        bool b = false;
        if(s2[j]==s3[index] && j<s2.size()){
            b = solve(s1,s2,s3,i,j+1,index+1,dp);
        }

        dp[i][j] = a || b;
        return dp[i][j];
        
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=n+m)
            return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
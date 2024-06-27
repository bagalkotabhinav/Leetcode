class Solution {
public:
    bool ans(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp){
        if(k==s3.size())
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool a=false;
        if(i<s1.size() && s1[i]==s3[k])
            a=ans(s1,s2,s3,i+1,j,k+1,dp);
        
        bool b=false;
        if(j<s2.size() && s2[j]==s3[k])
            b=ans(s1,s2,s3,i,j+1,k+1,dp);
        
        dp[i][j]=a || b;

        return dp[i][j];        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return ans(s1,s2,s3,0,0,0,dp);
    }
};
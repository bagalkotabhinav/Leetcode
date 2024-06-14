class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(auto i: dp){
        //     for(auto j: i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};

// take text1 from 0 to len by traversal from 0 to len(txt1)-1
// for each substring, traverse text2 from 0 to len(text2)-1
//look out for common subsequence

//abcd and ac = abc and a + 1 if d==c else max(abc and ac,abcd,a)
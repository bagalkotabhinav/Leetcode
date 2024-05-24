class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;i++){
            if(dp[i]){
                for(auto word: wordDict){
                    if(word==s.substr(i,word.size()))
                        dp[i+word.size()]=true;
                }
            }
        }
        return dp[n];
    }
};
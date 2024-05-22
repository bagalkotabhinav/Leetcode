class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        // Initialisation for index 1 element if checked for 2 digit number
        dp[0]=1;    
        // Initialisation for index 0 element is in between 1 and 9 (non 0)
        dp[1]=1;
        
        for(int i=2;i<=s.size();i++){
            int ones=stoi(s.substr(i-1,1));
            if(ones>=1 && ones <=9)
                dp[i]+=dp[i-1];
            int tens=stoi(s.substr(i-2,2));
            if(tens>=10 && tens<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
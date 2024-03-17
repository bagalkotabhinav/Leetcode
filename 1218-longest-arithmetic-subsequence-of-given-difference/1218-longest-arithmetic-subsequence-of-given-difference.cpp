class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        unordered_map<int,int> dp;
        for(int i=0;i<arr.size();i++){
            int count=0;
            if(dp.count(arr[i]-difference)){
                count=dp[arr[i]-difference];
            }
            dp[arr[i]]=1+count;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
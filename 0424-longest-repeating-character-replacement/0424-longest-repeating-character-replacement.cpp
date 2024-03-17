class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        vector<int> count(26);
        int l=0,r=0;
        int maxfreq=0;
        int ans=0;

        while(r<s.size()){
            count[s[r]-'A']++;
            maxfreq=max(maxfreq,count[s[r]-'A']);
            if(r-l+1-maxfreq>k){
                count[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
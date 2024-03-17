class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(128,-1);
        int maxi=0,l=0;
        for(int r=0;r<s.size();r++){
    //REPEATED AND l INDEX IS BEHIND THE FIRST OCCURRENCE OF REPEAT CHAR: s[r]
    //TO ADVANCE l BEYOND THE FIRST OCCURRENCE OF REPEATED CHAR
            if(index[s[r]]>=l){
                l=index[s[r]]+1;
            }
            maxi=max(maxi,r-l+1);
            index[s[r]]=r;
        }
        return maxi;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="") return s;
        string ans=s.substr(0,1);
        int l,r;
        for(int i=0;i<s.size();i++){
            l=i-1;
            r=i+1;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1>ans.size()){
                ans=s.substr(l+1,r-l-1);
            }
            l=i;
            r=i+1;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1>ans.size()){
                ans=s.substr(l+1,r-l-1);
            }
        }
        return ans;
    }
};
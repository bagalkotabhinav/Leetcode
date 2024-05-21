class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int l,r;
        for(int i=0;i<s.size();i++){
            l=i;
            r=i;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};
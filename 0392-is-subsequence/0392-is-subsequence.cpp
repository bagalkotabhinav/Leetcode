class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        for(i=0;i<t.length() && j<s.length();i++){
            if(t[i]==s[j]){
                j++;
            }
        }
        if(j==s.size()){
            return 1;
        }
        else{
            return 0;
        }
    }
};

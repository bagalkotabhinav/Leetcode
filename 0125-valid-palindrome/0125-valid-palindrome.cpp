class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string t;
        for(auto i: s){
            if((i>='a' && i<='z') || (i>='0' && i<='9'))
                t+=i;
        }
        int i=0;
        int j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
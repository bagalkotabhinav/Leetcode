class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto i: s){
            mp[i]++;
        }
        int odd=0;
        for(auto i: mp){
            if(i.second%2==1)
                odd++;
        }
        if(odd==1 || odd==0)
            return s.size();
        return s.size()-odd+1;
    }
};
class Solution {
public:
    bool isvalid(vector<int>& count){
        for(auto i: count){
            if(i!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;

        vector<int> count(26,0);
        
        for(int i=0;i<m;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        if(isvalid(count)) return true;

        for(int i=m;i<n;i++){
            count[s2[i]-'a']--;
            count[s2[i-m]-'a']++;
            if(isvalid(count)) return true;
        }
        return false;
    }
};
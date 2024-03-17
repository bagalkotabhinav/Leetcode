class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<pow(2,k)){
            return false;
        }
        unordered_set<string> keys;
        string temp;
        for(int i=0;i<=s.size()-k;i++){
            temp=s.substr(i,k);
            keys.insert(temp);
        }
        if(keys.size()==pow(2,k))
            return true;
        return false;
    }
};
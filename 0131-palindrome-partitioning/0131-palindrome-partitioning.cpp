class Solution {
public:
    bool ispal(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s, vector<string>& cur, vector<vector<string>>& ans, int start){
        if(start==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(ispal(s,start,i)){
                cur.push_back(s.substr(start,i-start+1));
                solve(s,cur,ans,i+1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        solve(s,cur,ans,0);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map <string,vector<string>> hm;
        vector<vector<string>> ans;

        for(auto i: strs){
            string s=i;
            sort(s.begin(),s.end());
            hm[s].push_back(i);
        }

        for(auto i:hm){
            ans.push_back(i.second);
        }
        return ans;
    }
};
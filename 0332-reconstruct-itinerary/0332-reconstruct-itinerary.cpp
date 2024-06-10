class Solution {
public:
    // void dfs(unordered_map<string,multiset<string>>& mp, vector<string>& ans, string start){
    //     while(!mp[start].empty()){
    //         string temp=*mp[start].begin();
    //         mp[start].erase(mp[start].begin());
    //         dfs(mp,ans,temp);
    //     }
    //     ans.push_back(start);
    // }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> mp;
        for(auto i: tickets){
            mp[i[0]].insert(i[1]);
        }
        vector<string> ans;
        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            string temp=s.top();
            if(!mp[temp].size()){
                ans.push_back(temp);
                s.pop();
            }
            else{
                auto val=mp[temp].begin();
                s.push(*val);
                mp[temp].erase(val);
            }
        }
        // dfs(mp,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// JFK->ANU TIA
// ANU->JFK EZE TIA
// EZE->AXA
// AXA->TIA
// TIA->ANU ANU JFK
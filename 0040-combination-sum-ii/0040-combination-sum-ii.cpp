class Solution {
public:
    void solve(int i,vector<int>& candidates, int target, vector<int>& curcomb,vector<vector<int>>& ans){
        if(target==0 && !count(ans.begin(),ans.end(),curcomb)){
            ans.push_back(curcomb);
            return;
        }
        
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])
                continue;
            if(target>=candidates[j]){
                curcomb.push_back(candidates[j]);
                solve(j+1,candidates,target-candidates[j],curcomb,ans);
                curcomb.pop_back();
                
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curcomb;
        solve(0,candidates,target,curcomb,ans);
        return ans;
    }
};
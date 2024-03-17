class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& temp, int index, vector<vector<int>>& ans){
        if(target==0 && count(ans.begin(),ans.end(),temp)==0){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(target-candidates[i]>=0){
                temp.push_back(candidates[i]);
                solve(candidates,target-candidates[i],temp,i+1,ans);
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,temp,0,ans);
        return ans;
    }
};



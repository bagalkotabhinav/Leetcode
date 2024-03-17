class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i==candidates.size() || target<0)
            return;
        if(target==0){
            ans.push_back(temp);
            return;
        }

        //PICK ELEMENT
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i,temp,ans);
        temp.pop_back();

        //NOT PICK ELEMENT
        solve(candidates,target,i+1,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,temp,ans);
        return ans;
    }
};
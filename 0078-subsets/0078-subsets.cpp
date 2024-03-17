class Solution {
public:
    void solve(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& temp){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,i+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,0,ans,temp);
        return ans;
    }
};
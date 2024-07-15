class Solution {
public:
    void ans(vector<int>& nums, int ind, int k, vector<int>& res, vector<vector<int>>& pow){
        if(ind>=nums.size())
            return;
        if(k==0){
            pow.push_back(res);
            return;
        }
        else if(k<0)
            return;
        for(int i=ind;i<nums.size();i++){
            res.push_back(nums[i]);
            ans(nums,i,k-nums[i],res,pow);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> pow;
        ans(candidates,0,target,res,pow);
        return pow;
    }
};
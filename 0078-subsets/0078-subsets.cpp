class Solution {
public:
    void ans(vector<int>& nums, int index, vector<vector<int>>& pow, vector<int>& res){
        if(index>nums.size())
            return;
        pow.push_back(res);
        for(int i=index;i<nums.size();i++){
            res.push_back(nums[i]);
            ans(nums,i+1,pow,res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> pow;
        ans(nums,0,pow,res);
        return pow;
    }
};
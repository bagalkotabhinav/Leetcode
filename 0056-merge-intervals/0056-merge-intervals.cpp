class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums[0]);
        if(n==1)
            return ans;
        
        for(int i=1;i<n;i++){
            if(ans.back()[1]<nums[i][0])
                ans.push_back(nums[i]);
            else
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
        }
        return ans;
    }
};
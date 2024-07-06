class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),ans=nums.size();
        for(int i=0;i<n;i++){
            ans=ans^i^nums[i];
        }
        return ans;
    }
};  
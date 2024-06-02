class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=nums[0];
        for(auto i: nums){
            sum=max(sum+i,i);
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
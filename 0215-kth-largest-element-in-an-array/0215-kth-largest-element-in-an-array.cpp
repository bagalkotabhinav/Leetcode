class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return(nums[n-k]);
    }
};
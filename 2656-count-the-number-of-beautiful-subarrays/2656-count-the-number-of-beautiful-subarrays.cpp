class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int xr=0;
        mp[xr]++;
        long long int count=0;
        for(int i=0;i<nums.size();i++){
            xr=xr^nums[i];
            int x=xr^0;
            count+=mp[x];
            mp[xr]++;
        }
        return count;
    }
};
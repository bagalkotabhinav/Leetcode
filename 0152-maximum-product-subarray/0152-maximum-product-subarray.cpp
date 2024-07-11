class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=1,mini=1,ans=nums[0];
        for(auto i: nums){
            int maxim=maxi*i;
            int minim=mini*i;
            int curmax=max(maxim,minim);
            int curmin=min(maxim,minim);
            maxi=max(curmax,i);
            mini=min(curmin,i);
            ans=max(ans,maxi);
        }
        return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=1,min_prod=1,ans=nums[0];
        for(auto i: nums){
            int max_temp=max_prod*i;
            int min_temp=min_prod*i;
            int curmax=max(max_temp,min_temp);
            int curmin=min(max_temp,min_temp);
            max_prod=max(curmax,i);
            min_prod=min(curmin,i);
            ans=max(ans,max_prod);
        }
        return ans;
    }
};

// max_prod: stores max of: all elements till current index and current number
// min_prod: stores min of: all elements till current index and current number
// during each iteration, store maximum
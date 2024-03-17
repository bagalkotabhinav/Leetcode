class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxi)
                return false;
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};
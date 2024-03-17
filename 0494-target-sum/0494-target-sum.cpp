class Solution {
public:
    int ans(int i, int total, int target, vector<int>& nums){
        if(i==nums.size()){
            if(total==target)
                return 1;
            else
                return 0;
        }
        int x=ans(i+1,total+nums[i],target,nums);

        int y=ans(i+1,total-nums[i],target,nums);

        return (x+y);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
            ios_base::sync_with_stdio(false);

    cin.tie(NULL);

        return ans(0,0,target,nums);
    }
};
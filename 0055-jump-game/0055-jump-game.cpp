class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0;
        for(int i=0;i<nums.size();i++){
            if(i>jump)
                return false;
            //max jump position till index i
            jump=max(i+nums[i],jump);
            if(jump>=nums.size()-1)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=-1,temp,index=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>ans){
                ans=nums[i];
                index=i;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(i!=index){
                if(ans<2*nums[i]){
                    index=-1;
                    break;
                }
            }
        }
        return index;
    }
};
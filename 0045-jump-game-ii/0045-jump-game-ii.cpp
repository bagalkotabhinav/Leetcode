class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<n;i++){
            nums[i]=max(i+nums[i],nums[i-1]);
        }

        int i=0,ans=0;

        while(i<n-1){
            ans++;
            i=nums[i];
        }

        return ans;
    }
};
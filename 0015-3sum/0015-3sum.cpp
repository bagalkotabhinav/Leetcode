class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i,j,k;
        for(int i=0;i<=nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    j++;
                    while(j<k && nums[k]==nums[k-1])
                        k--;
                    k--;
                }
                else if(sum>0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
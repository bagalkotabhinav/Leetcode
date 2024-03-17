class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans(nums.size(),1);
        int temp=1;

        for(int i=0;i<nums.size();i++){
            ans[i]=ans[i]*temp;
            temp=temp*nums[i];
        }
        temp=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=ans[i]*temp;
            temp=temp*nums[i];
        }

        return ans;
        
        
    }
};

// vector<int> prefix;
//         prefix.push_back(1);
//         for(int i=1;i<nums.size();i++){
//             prefix.push_back(prefix[i-1]*nums[i-1]);
//         }
//         vector<int> suffix;
//         reverse(nums.begin(),nums.end());
//         suffix.push_back(1);
//         for(int i=1;i<nums.size();i++){
//             suffix.push_back(suffix[i-1]*nums[i-1]);
//         }
//         reverse(suffix.begin(),suffix.end());
//         vector<int> ans;
//         for(int i=0;i<nums.size();i++){
//             ans.push_back(prefix[i]*suffix[i]);
//         }
        
        
        
//         return ans;
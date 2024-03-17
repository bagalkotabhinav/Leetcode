class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=nums.size()-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j+1]==nums[j]){
                        j++;
                    }
                    while(j<k && nums[k-1]==nums[k]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};






// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> a1;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             int temp=i;
//             int j=i+1,k=nums.size()-1;
//             vector<int> a;
//             while(j<k){
//                 if((nums[i]+nums[j]+nums[k])==0){
//                     a.push_back(nums[i]);
//                     a.push_back(nums[j]);
//                     a.push_back(nums[k]);
//                     ans.push_back(a);
//                     a1.insert(a);
//                     a.clear();
                    
//                     i=temp;
//                     j++;
//                     k--;
                
//                 }
//                 else if((nums[i]+nums[j]+nums[k])<0){
//                     j++;
//                 }
//                 else if((nums[i]+nums[j]+nums[k])>0){
//                     k--;
//                 }
//             }
//         }
//        vector<vector<int>> a2(a1.begin(),a1.end());
//         return a2;
//     }
// };
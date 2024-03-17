class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        int n1;
        unordered_map <int,int> hm;
        for(int i=0;i<nums.size();i++){
            n1=nums[i];
            if(hm.find(target-n1)==hm.end()){
                hm[n1]=i;
            }
            else{
                ans.push_back(hm[target-n1]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
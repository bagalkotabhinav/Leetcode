class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int,int> num;

        for(auto i:nums){
            num[i]++;
            
            if(num[i]>1)
                return true;
            
        }
        return false;
    }
};
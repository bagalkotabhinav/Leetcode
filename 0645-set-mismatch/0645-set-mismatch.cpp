class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        
        vector<int> rep;
        int n=nums.size();
        int i_sum=(n*(n+1))/2;
        unordered_set<int> uni;
        for(int i=0;i<n;i++){
            if(uni.count(nums[i])){
                rep.push_back(nums[i]);
            }
            uni.insert(nums[i]);
        }
        int s_sum=accumulate(uni.begin(),uni.end(),0);
        rep.push_back(i_sum-s_sum);
        return rep;
    }
};

//set
//all unique elements
//nums-set=duplicate element

//ideal sum=n*n+1/2
//missing element=ideal sum-set sum
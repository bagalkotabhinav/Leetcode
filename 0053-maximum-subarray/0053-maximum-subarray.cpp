class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0,maxi=nums[0];
        for(auto i: nums){
            sum=sum+i;
            if(sum>maxi)
                maxi=sum;
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};

//for i=0 to n
//sum=0
//maxi=max sum (initialise to arr[0])
//if sum<=0, update sum to 0
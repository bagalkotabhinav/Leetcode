class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN/2;
        for(auto i: nums){
            sum=sum+i;
            maxi=max(maxi,sum);
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0,segment=0;
        int checksegment=nums[0]%2;
        for(auto i: nums){
            if(i%2==0)
                even++;
            else
                odd++;
            if(i%2==checksegment){
                segment++;
                checksegment=1-checksegment;
            }
        }
        return max({even,odd,segment});
    }
};
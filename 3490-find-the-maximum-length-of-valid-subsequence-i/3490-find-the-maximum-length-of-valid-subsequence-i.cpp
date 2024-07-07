class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0,alternate=nums[0]%2,segment=0;
        for(auto i: nums){
            if(i%2==0)
                even++;
            else
                odd++;
            if(i%2==alternate){
                segment++;
                alternate=1-alternate;
            }
        }
        return max({odd,even,segment});
    }
};
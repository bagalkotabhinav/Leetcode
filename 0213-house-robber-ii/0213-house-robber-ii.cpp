class Solution {
public:
    int house(vector<int>& nums, int start, int end){
        int first=nums[start];
        int second=max(nums[start],nums[start+1]);
        int third;
        for(int i=start+2;i<=end;i++){
            third=max(first+nums[i],second);
            first=second;
            second=third;
        }
        return third;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int a=house(nums,0,n-2);
        int b=house(nums,1,n-1);
        return max(a,b);
    }
};
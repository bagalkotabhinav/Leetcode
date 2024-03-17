class Solution {
public:
    int findMin(vector<int>& nums) {
        int fele=nums[0];
        int i=1;
        int j=nums.size()-1;
        int cur=fele;

        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>=fele){
                i=mid+1;
                cur=min(nums[mid],cur);
            }
            else if (nums[mid]<fele){
                j=mid-1;
                cur=min(nums[mid],cur);
            }
        }
        return cur;

    }
};
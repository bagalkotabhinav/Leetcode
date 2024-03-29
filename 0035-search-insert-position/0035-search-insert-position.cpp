class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n=nums.size();
        if(target>nums[n-1])
            return n;
        int l=0,r=n-1;


        while(l<r){
            int mid=(r+l)/2;
            if(nums[mid]>=target)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
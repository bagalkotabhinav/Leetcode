class Solution {
public:
    int bs(vector<int>& nums, int target, int i, int j){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                j=mid-1;
                return bs(nums,target,i,j);
            }
            else{
                i=mid+1;
                return bs(nums,target,i,j);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        return bs(nums,target,0,nums.size()-1);
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;

        //FIND JUST DECREASING ELEMENT FROM RIGHT
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        //LOOP TO FIRST ORDER
        if(i<0)
            reverse(nums.begin(),nums.end());

        else{
            //FIND JUST INCREASING ELEMENT FROM i
            for(j=nums.size()-1;j>=0;j--){
                if(nums[j]>nums[i])
                    break;
            }
            //LEXICOGRAPHICAL ORDER
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};


class Solution {
public:
    int sumv(vector<int> array, int s, int n){
        int sum=0;
        for(int i=s;i<=n;i++){
          sum=sum+array.at(i);
        }
        return sum;
    }

    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> array;
        int len=sizeof(nums)/sizeof(nums[0]);
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<nums.capacity();i++){
              array.push_back(nums[i]);
              if(sumv(array,0,array.size()-1)>sumv(nums,i+1,nums.size()-1)){
                  break;
              }
        }
        return array;
    }
};
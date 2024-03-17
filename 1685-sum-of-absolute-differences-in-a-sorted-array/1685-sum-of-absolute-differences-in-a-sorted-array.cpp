class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result;
        int length=nums.size();
        int m=0;
        int n=accumulate(nums.begin()+1,nums.end(),0);
        int ans=0;
        int i=0;

        while(i<=length-1){
            ans=(((2*i)-length+1)*nums[i])-m+n;
            result.push_back(ans);

            m=m+nums[i];
            i=i+1;
            if(i<=length-1)
                n=n-nums[i];
        }

        return result;
        
    }
};
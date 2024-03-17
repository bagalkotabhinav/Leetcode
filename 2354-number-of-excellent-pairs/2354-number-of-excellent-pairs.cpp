class Solution {
public:
    unsigned int countSetBits(unsigned int n)
    {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
            ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        vector<int> num;
        int x = -1;
        sort(nums.begin(),nums.end());
        for(int a : nums) {
            if(x == a) 
                continue; 
            else {
                x = a;
                num.push_back(countSetBits(a));
            }
        }
        
		sort(num.begin(),num.end());
		
        long long ans = 0;
        int i = 0 , j = num.size()-1,n = num.size();

        while(i<n){
            
            while(j>=0  && num[j]+num[i]>=k)
                j--;
            ans += n - j - 1;
            i++;
        }
        
        return ans;
    }
};
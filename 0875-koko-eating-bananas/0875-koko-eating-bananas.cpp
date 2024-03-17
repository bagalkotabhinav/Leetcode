class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int i=1;
        long long int j=*max_element(piles.begin(),piles.end());
        long long int mid;
        long long int ans=INT_MAX;

        while(i<=j){
            mid=(i+j)/2;
            long long int time=0;
            for(auto i: piles){
                time += (i + mid - 1) / mid;

            }
            if(time<=h){
                ans=min(ans,mid);
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};
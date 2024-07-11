class Solution {
public:
    long long int findtime(vector<int>& piles, int mid){
        long long int time=0;
        for(auto i: piles){
            time=time+ceil((double)i/(double)mid);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low=1,high=*max_element(piles.begin(),piles.end());
        long long int mid;
        long long int ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            long long int time=findtime(piles,mid);
            if(time<=h){
                high=mid-1;
                ans=min(ans,mid);
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
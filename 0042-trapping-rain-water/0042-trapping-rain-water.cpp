class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=height.size();
        int maxleft=height[0];
        int maxright=height[n-1];
        int i=0;
        int j=n-1;
        int ans=0;
        int cur=0;

        while(i<=j){
            if(maxleft<=maxright){
                cur=maxleft-height[i];
                if(cur>0)
                    ans+=cur;
                if(height[i]>maxleft)
                    maxleft=height[i];
                i++;
            }
            else{
                cur=maxright-height[j];
                if(cur>0)
                    ans+=cur;
                if(height[j]>maxright)
                    maxright=height[j];
                j--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxleft(n);
        vector<int> maxright(n);
        maxleft[0]=height[0];
        int ml=height[0];
        for(int i=1;i<n;i++){
            maxleft[i]=ml;
            if(height[i]>ml)
                ml=height[i];
        }
        maxright[n-1]=height[n-1];
        int mr=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxright[i]=mr;
            if(height[i]>mr)
                mr=height[i];
        }
        int ans=0;
        vector<int> water(n);
        for(int i=0;i<n;i++){
            water[i]=min(maxleft[i],maxright[i])-height[i];
        }
        for(auto i: water){
            if(i>0)
                ans+=i;
        }
        return ans;
    }
};
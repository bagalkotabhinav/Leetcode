class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int diff=INT_MIN;
        vector<int> x;
        for(auto i: points){
            x.push_back(i[0]);
        }
        sort(x.begin(),x.end());
        for(int i=1;i<x.size();i++){
            diff=max(diff,(x[i]-x[i-1]));
        }
        return diff;
    }
};
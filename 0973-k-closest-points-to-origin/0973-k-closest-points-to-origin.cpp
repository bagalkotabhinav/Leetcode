class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p,vector<p>,greater<p>> pq;
        for(auto&i: points){
            int x=i[0];
            int y=i[1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
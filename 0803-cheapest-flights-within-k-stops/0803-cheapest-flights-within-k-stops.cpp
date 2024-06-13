class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjmat(n);
        vector<int> distances(n,INT_MAX);
        for(auto i: flights){
            adjmat[i[0]].push_back({i[1],i[2]});
        }
        distances[src]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            int hops=pq.top()[0];
            int node=pq.top()[1];
            int cost=pq.top()[2];
            pq.pop();
            if(hops<=k){
                for(auto i: adjmat[node]){
                    int newnode=i.first;
                    int path=i.second;
                    if(cost+path<distances[newnode]){
                        distances[newnode]=cost+path;
                        pq.push({hops+1,newnode,cost+path});
                    }
                }
            }
        }
        return distances[dst]!=INT_MAX?distances[dst]:-1;
    }
};
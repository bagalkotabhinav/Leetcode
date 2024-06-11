class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjmat(n+1);
        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<times.size();i++){
            int source=times[i][0];
            int dest=times[i][1];
            int time=times[i][2];
            adjmat[source].push_back({time,dest});
        }

        pq.push({0,k});

        while(!pq.empty()){
            int minwt=pq.top().first;
            int minnode=pq.top().second;
            pq.pop();
            if(distance[minnode]!=INT_MAX)
                continue;
            distance[minnode]=minwt;

            for(auto i:adjmat[minnode]){
                pq.push({minwt+i.first,i.second});
            }  
        }
        int ans=*max_element(distance.begin()+1,distance.end());
        return ans!=INT_MAX?ans:-1;
    }
};
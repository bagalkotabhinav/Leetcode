class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long int> edges(n,0);
        for(auto i: roads){
            edges[i[0]]++;
            edges[i[1]]++;
        }
        sort(edges.begin(),edges.end());
        long long int ans=0;
        for(int i=0;i<edges.size();i++){
            ans=ans+(edges[i]*(i+1));
        }
        return ans;
    }
};

// More edges, higher importance
// count for each node, how many edges
// sort the number
// muliply with starting from 1 till n the sorted number
// sum up all

// 0 1 2 3 4
// 2 3 4 2 1
// 1 2 2 3 4
// 1 2 3 4 5
// 1 4 6 12 2
// 2 4 5 3 1

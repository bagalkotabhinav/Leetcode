class Solution {
public:
    bool valid(int col, vector<int>& color, int n, vector<int> paths[], int curnode){
        for(auto i: paths[curnode]){
            if(color[i]==col)
                return false;
        }
        return true;
    }
    bool solve(int n, vector<int> paths[], int m, int curnode,vector<int>& color){
        if(curnode==n+1)
            return true;
        for(int col=1;col<=m;col++){
            if(valid(col,color,n,paths,curnode)){
                color[curnode]=col;
                if(solve(n,paths,m,curnode+1,color))
                    return true;
                else
                    color[curnode]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> graph[n+1];
        for(auto i: paths){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> color(n+1,0);
        solve(n,graph,4,1,color);
        vector<int> ans;
        for(auto i: color){
            if(i!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
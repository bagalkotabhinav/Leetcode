class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int ans=max(grid[0][0],grid[n-1][n-1]);
        pq.push({ans,0,0});
        vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()){
            int x=pq.top()[1];
            int y=pq.top()[2];
            int temp=pq.top()[0];
            ans=max(ans,temp);
            pq.pop();
            if(x==n-1 && y==n-1)
                return ans;
            for(int i=0;i<4;i++){
                int nx=move[i][0];
                int ny=move[i][1];
                if(x+nx>=0 && x+nx<=n-1 && y+ny>=0 && y+ny<=n-1 && !visited[x+nx][y+ny]){
                    int res=grid[x+nx][y+ny];
                    pq.push({res,x+nx,y+ny});
                    visited[x+nx][y+ny]=true;
                }
            }
        }
        return 0;
    }
};
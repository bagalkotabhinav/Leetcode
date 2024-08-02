class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int ans=0;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        if(fresh==0)
            return 0;
        while(!q.empty()){
            int s=q.size();
            if(fresh==0)
                return ans;
            while(s--){
                auto rot=q.front();
                q.pop();
                int x=rot.first;
                int y=rot.second;
                for(auto d: dir){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
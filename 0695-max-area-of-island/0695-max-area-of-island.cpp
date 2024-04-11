class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int row, int col, int& ans){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0)
            return;
        grid[i][j]=0;
        ans++;
        vector<int> m1={0,0,1,-1};
        vector<int> m2={1,-1,0,0};
        for(int k=0;k<4;k++){
            int nx=i+m1[k];
            int ny=j+m2[k];
            dfs(grid,nx,ny,row,col,ans);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    dfs(grid,i,j,row,col,ans);
                    maxi=max(maxi,ans);
                }
            }
        }
        return maxi!=INT_MIN?maxi:0;
    }
};
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int row, int col, int& ans){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        ans+=1;
        int a=dfs(grid,i+1,j,row,col,ans);
        int b=dfs(grid,i-1,j,row,col,ans);
        int c=dfs(grid,i,j+1,row,col,ans);
        int d=dfs(grid,i,j-1,row,col,ans);
        return 1+a+b+c+d;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ans=0;
                int res=dfs(grid,i,j,row,col,ans);
                maxi=max(maxi,res);
            }
        }
        return maxi;
    }
};
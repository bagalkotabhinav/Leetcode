class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int row, int col){
        visited[x][y]=true;
        int m1[4]={1,-1,0,0};
        int m2[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx=x+m1[i];
            int ny=y+m2[i];
            if(nx>=0&&nx<row&&ny>=0&&ny<col&&!visited[nx][ny]&&heights[nx][ny]>=heights[x][y])
                dfs(heights,visited,nx,ny,row,col);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        vector<vector<int>> result;

        for(int i=0;i<col;i++){
            dfs(heights,pacific,0,i,row,col);
            dfs(heights,atlantic,row-1,i,row,col);
        }
        for(int j=0;j<row;j++){
            dfs(heights,pacific,j,0,row,col);
            dfs(heights,atlantic,j,col-1,row,col);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
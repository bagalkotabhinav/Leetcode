class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        for(int i=0;i<grid.size();i++){
            int col=grid[i].size();
            for(int j=0;j<col;j++){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }
        return count;
    }
};
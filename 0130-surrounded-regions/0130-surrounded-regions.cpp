class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col){
        if(i<0 || i>=row || j<0 || j>=col || board[i][j]!='O')
            return;
        board[i][j]='K';
        dfs(board,i-1,j,row,col);
        dfs(board,i+1,j,row,col);
        dfs(board,i,j-1,row,col);
        dfs(board,i,j+1,row,col);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            dfs(board,i,0,row,col);
            dfs(board,i,col-1,row,col);
        }
        for(int j=0;j<col;j++){
            dfs(board,0,j,row,col);
            dfs(board,row-1,j,row,col);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='K')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};

//mark bordering islands with special character
//then, mark special character with o and o with x

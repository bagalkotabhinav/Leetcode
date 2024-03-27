class Solution {
public:
    bool isSafe(int n, vector<string>& board, int row, int col){
        //CHECK ROW
        for(int r=0;r<row;r++){
            if(board[r][col]=='Q')
                return false;
        }

        //CHECK UPPER LEFT DIAG
        for(int r=row,c=col; r>=0 && c>=0; r--,c--){
            if(board[r][c]=='Q')
                return false;
        }

        //CHECK UPPER RIGHT DIAG
        for(int r=row,c=col; r>=0 && c<n; r--,c++){
            if(board[r][c]=='Q')
                return false;
        }

        return true;
    }
    void NQueens(int n, int row, vector<string>& board, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(n,board,row,col)){
                board[row][col]='Q';
                NQueens(n,row+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n==2 || n==3)
            return ans;
        
        vector<string> board(n,string(n,'.'));
        NQueens(n,0,board,ans);
        return ans;
    }
};
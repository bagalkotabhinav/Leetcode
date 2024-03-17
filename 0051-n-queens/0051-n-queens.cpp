class Solution {
public:
    bool safe(int row, int col, vector<string>& board, int n){
        int r=row;
        int c=col;
        
        //ROW
        for(int ro=0;ro<r;ro++){
            if(board[ro][col]=='Q')
                return false;
        }

        //UPPER RIGHT DIAG
        row=r;
        col=c;
        while(row>=0 && col<=n-1){
            if(board[row][col]=='Q')
                return false;
            row--;
            col++;
        }

        //UPPER LEFT DIAG
        row=r;
        col=c;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        return true;
    }
    void solve(int n, vector<string>& board, vector<vector<string>>& ans, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(n,board,ans,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(n,board,ans,0);
        return ans;        
    }
};
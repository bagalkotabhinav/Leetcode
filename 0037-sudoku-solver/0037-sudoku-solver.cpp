class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int i, int j, char n){
        for(int k=0;k<9;k++){
            if(board[i][k]==n)
                return false;
            if(board[k][j]==n)
                return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==n)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char n='1';n<='9';n++){
                        if(isvalid(board,i,j,n)){
                            board[i][j]=n;
                            if(solve(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
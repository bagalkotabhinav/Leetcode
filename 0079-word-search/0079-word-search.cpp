class Solution {
public:
    bool solve(const int& m, const int& n, vector<vector<char>>& board, int i, int j, string& word, int k){
        if(k==word.size())
            return true;
        if(i==m || j==n || i<0 || j<0 || board[i][j]!=word[k])
            return false;
        
        char c=board[i][j];
        board[i][j]='.';

        bool top=solve(m,n,board,i-1,j,word,k+1);
        bool down=solve(m,n,board,i+1,j,word,k+1);
        bool left=solve(m,n,board,i,j-1,word,k+1);
        bool right=solve(m,n,board,i,j+1,word,k+1);

        board[i][j]=c;

        return top||down||left||right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(m,n,board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};


// index k to map word's current character to current word in board (board[i][j])
// if it is not equal to word[k], it means cannot get word from current cell, return false
// if it is equal, check for all positions: up, down, left, right
// if any one of them returns true, then final word can be reached with current cell (board[i][j])
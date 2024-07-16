class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int k){
        if(k>=word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k])
            return false;
        char c=board[i][j];
        board[i][j]='#';
        bool top=solve(i-1,j,board,word,k+1);
        bool down=solve(i+1,j,board,word,k+1);
        bool left=solve(i,j-1,board,word,k+1);
        bool right=solve(i,j+1,board,word,k+1);
        board[i][j]=c;
        return top||down||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
};
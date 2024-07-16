class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, int k, string& word){
        if(k>=word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k])
            return false;

        char c=board[i][j];
        board[i][j]='#';
        bool top=solve(i-1,j,board,k+1,word);
        bool bottom=solve(i+1,j,board,k+1,word);
        bool right=solve(i,j+1,board,k+1,word);
        bool left=solve(i,j-1,board,k+1,word);
        board[i][j]=c;
        return top||bottom||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,board,0,word))
                    return true;
            }
        }
        return false;
    }
};
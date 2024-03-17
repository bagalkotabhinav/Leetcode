class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        //ROW
        for(auto i: board){
            set<char> number;
            for(int j=0;j<i.size();j++){
                if(isdigit(i[j]) && (number.find(i[j])!=number.end())){
                    cout<<i[j]<<endl;
                    return false;
                }
                number.insert(i[j]);
            }
            number.clear();
        }

        //COL
        for(int i=0;i<board.size();i++){
            set<char> number;
            for(int j=0;j<board.size();j++){
                if(isdigit(board[j][i]) && (number.find(board[j][i])!=number.end())){
                    cout<<board[j][i]<<endl;
                    return false;
                }
                number.insert(board[j][i]);
            }
            number.clear();
        }

        //BOX

        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                set<char> number;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(isdigit(board[i+r][j+c])){
                            if(number.find(board[i+r][j+c])!=number.end()){
                                cout<<board[i+r][j+c]<<endl;
                                return false;
                            }
                            else{
                                number.insert(board[i+r][j+c]);
                            }
                        }
                    }
                }
                number.clear();
            }
        }
        return true;
    }
};
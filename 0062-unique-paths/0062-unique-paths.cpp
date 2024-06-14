class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> adjmat(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
            adjmat[0][i]=1;
        for(int i=0;i<m;i++)
            adjmat[i][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                adjmat[i][j]=adjmat[i-1][j]+adjmat[i][j-1];
            }
        }
        return adjmat[m-1][n-1];
    }
};
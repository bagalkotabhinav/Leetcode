class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        vector<vector<int>> adjmat(m,vector<int>(n,0));
        for(int i=0;i<m-1;i++)
            adjmat[i][n-1]=1;
        for(int i=0;i<n-1;i++)
            adjmat[m-1][i]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                adjmat[i][j]=adjmat[i+1][j]+adjmat[i][j+1];
            }
        }
        return adjmat[0][0];
    }
};
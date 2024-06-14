class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        vector<vector<int>> adjmat(m,vector<int>(n,-1));
        adjmat[m-1][n-1]=0;
        for(int i=m-2;i>=0;i--)
            adjmat[i][n-1]=1;
        for(int i=n-2;i>=0;i--)
            adjmat[m-1][i]=1;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                adjmat[i][j]=adjmat[i+1][j]+adjmat[i][j+1];
            }
        }
        // cout<<adjmat[0][0]<<endl;
        return adjmat[0][0];
    }
};

//can go right
//can go down
//recursion
//edge cases
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m1[4]={1,-1,0,0};
        int m2[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        int row=grid.size();
        int col=grid[0].size();
        int min=-1;
        int fresh=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+m1[i];
                    int ny=y+m2[i];
                    if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            min++;
        }
        return fresh>0?-1:min;
    }
};

//queue
//enter coordinates of 2 in queue
//while !q.emoty
//pop queue
//find adjacent coordinate values
//if any 1 present, push into queue and do min++
// else, continue
//lastly, verify if any 1 is left if yes, return -1, else return min


//initially 1 ele, so 1 iteration
//then 2 new added, so 2 new iteration
//then 2 new added, so 2 new iteration
//then 1 new added, so 1 new iteration
//then 1 new added, so 1 new iteration
//for this, use cur size for queue
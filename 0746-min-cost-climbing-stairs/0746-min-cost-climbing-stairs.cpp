class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first=0;
        int second=0;
        int third;
        for(int i=2;i<=n;i++){
            third=min(first+cost[i-2],second+cost[i-1]);
            first=second;
            second=third;
        }
        return third;
    }
};

//dp[i]=cost to reach dp[i-2]+cost[i-2] or cost to reach dp[i-1]+cost[i-1]
//dp[0]=0 dp[1]=0 dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
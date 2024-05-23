class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//DP ARRAY: dp[i]= min number of coins from given coin array to amount to i
// dp[3]=min coins required that make up 3 from given denomination
        vector<int> dp(amount+1,INT_MAX/2);
        dp[0]=0;

// for each value 1 to amount, try to divide it thru all given denominations
// amt=11: 1 thru all 1,2,5: 2 thru all 1,2,5...... 11 thru all 1,2,5
        for(int value=1;value<=amount;value++){
            for(auto denomination: coins){
                if(value-denomination>=0){
                    dp[value]=min(dp[value],1+dp[value-denomination]);
                }
            }
        }
        return dp[amount]!=INT_MAX/2?dp[amount]:-1;
    }
};
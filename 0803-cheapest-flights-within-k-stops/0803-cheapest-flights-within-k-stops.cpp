class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX); //Cost to reach each node from src node
        prices[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int> temp(prices.begin(),prices.end());
            for(auto i: flights){
                int s=i[0];
                int d=i[1];
                int p=i[2];
                if(prices[s]==INT_MAX)
                    continue;
                if(prices[s] + p < temp[d])
                    temp[d] = prices[s] + p;
            }
            prices=temp;
        }
        return prices[dst]!=INT_MAX?prices[dst]:-1;
    }
};
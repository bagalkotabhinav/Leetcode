class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(piles.begin(),piles.end());

        int n=piles.size();
        int m=n-2;
        int count=0;

        while(m>=n/3){
                count=count+piles[m];
                m=m-2;
        }

        return count;

    }
};

// int maxCoins(vector<int>& piles) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         sort(piles.begin(),piles.end());

//         int ans=0;

//         while(piles.size()>=3){
//             ans=ans+piles[piles.size()-2];

//             piles.pop_back();
//             piles.pop_back();
//             piles.erase(piles.begin());
//         }

//         return ans;

//     }
class Solution {
public:
    int setbits(int i){
        int ans=0;
        while(i){
            if(i&1)
                ans++;
            i=i>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=0;i<=n;i++){
            ans[i]=setbits(i);
        }

        return ans;
    }
};
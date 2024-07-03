class Solution {
public:
    int setbits(int num){
        int cnt =0;
        while(num != 0){
            num = num & (num-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=0;i<=n;i++){
            ans[i]=setbits(i);
        }

        return ans;
    }
};
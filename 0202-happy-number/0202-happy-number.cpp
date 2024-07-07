class Solution {
public:
    int ans(int n){
        int sum=0;
        while(n){
            int rem=n%10;
            n/=10;
            sum+=pow(rem,2);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=ans(n);
        while(slow!=fast && fast!=1){
            slow=ans(slow);
            fast=ans(ans(fast));
        }
        if(fast==1)
            return true;
        return false;
    }
};
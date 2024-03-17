#include <bits/stdc++.h>
class Solution {
public:
    double Pow(double x, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=abs(k);
        if(n==0 || x==1)
            return 1;
            if(n%2==0)
                return myPow(x*x,n/2);
            return x*myPow(x,n-1);
    }
    double myPow(double x, int k) {
        
        double ans=Pow(x,abs(k));
        if(k>0)
            return ans;
        return(1/ans);
    }
};
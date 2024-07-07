class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            x=1/x;
        double pow=1;
        long num=labs(n);
        while(num){
            if(num&1)
                pow=pow*x;
            x=x*x;
            num=num>>1;
        }
        return pow;
    }
};

// x=7 n=11
// 11=(1011)2 == 8+2+1
// 7^11= 7^8 + 7^2 + 7^1
// x=7
// pow*=x iff n&1==1
// x*=x
class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry=(a&b);
            a=(a^b);
            b=carry<<1;
        }
        return a;
    }
};
// 10
// 11
// carry=10
// a=01
// b=100

// carry=000
// a=101
// b=0000

// return 101
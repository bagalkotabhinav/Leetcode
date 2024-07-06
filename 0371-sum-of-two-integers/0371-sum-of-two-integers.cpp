class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry=a&b;
            a=a^b;
            b=carry<<1;
        }
        return a;
    }
};

//  AND both
// XOR both and store in one number
// LEFT SHIFT ANDed number by 1 and store in other number
// repeat till second number becomes 0
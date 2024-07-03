class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n){
            if(n&1)
                count++;
            n>>=1;
        }
        return count;
    }
};

// 1011
// 0001
// ----
// 0001   -> count=1
// right shift

// 0101
// 0001
// ----
// 0001   -> count=2
// right shift

// 0010
// 0001
// ----
// 0000   -> count=2
// right shift

// 0001
// 0001
// ----
// 0001    ->count=3
// right shift

// 0000 STOP
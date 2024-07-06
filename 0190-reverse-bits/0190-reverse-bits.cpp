class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            // GET ith BIT VALUE
            uint32_t bit=(n>>i)&1;
            // APPEND ith BIT VALUE TO 31-ith POSITION
            ans=ans|bit<<(31-i);
        }
        return ans;
    }
};
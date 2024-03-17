class Solution {
public:
    int findComplement(int num) {
        int bit=0,ans=0,i=0;
        while(num>0){
            bit=num&1;
            if(bit==0)
                bit=1;
            else
                bit=0;

            ans=ans+(bit)*pow(2,i);
            i++;
            num=num>>1;

        }
        return ans;
    }
};
class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        while(n!=0){
            int rem=n%10;
            n=n/10;
            sum=sum+pow(rem,2);
        }
        if(sum==1)
            return true;
        if(sum>0 && sum<9){
            if(sum==1 || sum==7)
                return true;
            else
                return false;
        }
        return isHappy(sum);
    }
};
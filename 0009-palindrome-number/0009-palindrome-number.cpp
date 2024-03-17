class Solution {
public:
    int reverse(int n){
        long long int num=0,k;
        while(n>0){
            k=n%10;
            num=(num*10)+(k);
            n=n/10;
        }
        return num;
    }
    bool isPalindrome(int x) {
        int revx=reverse(x);
        if(x==revx)
            return true;
        return false;
    }
};
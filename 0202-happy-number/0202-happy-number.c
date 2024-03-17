

bool isHappy(int n){
    int sum=0,rem=0;
    while (n>0){
        rem=n%10;
        sum+=rem*rem;
        n/=10;
    }
    if(sum==1){
        return true;
    }
    else if (sum>0 && sum<9){
        if (sum==1 || sum==7){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return isHappy(sum);
    }
}
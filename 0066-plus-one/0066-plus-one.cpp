class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};

//digits[size-1]+=1
// digits[size-1] is >=10, put rem as digits[size-1], continue
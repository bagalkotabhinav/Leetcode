class Solution {
public:
    
    int minFlips(string s) {
         int count=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1' && s[i+1]=='0'){
                count++;
            }
            else{
                count=count;
            }
        }
        if(s[s.length()-1]=='1')
            return (2*count)+1;
        else
            return (2*count);
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int i=s.size()-1;
        // if(i==0)
        //     return 1;
        while(s[i]==' ')
            i--;
        while(i>=0&&s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};
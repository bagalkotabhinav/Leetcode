class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen=s.size(),tlen=t.size();
        int i=0,j=0;
        while(i<slen && j<tlen){
            if(s[i]==t[j])
                j++;
            i++;
        }
        return tlen-j;
    }
};
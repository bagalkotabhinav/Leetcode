class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        unordered_map<char,int> freq;

        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }

        int i=0,j=0;
        int length=INT_MAX,start=0;
        int count=t.size();

        while(j<s.size()){
            if(freq[s[j]]>0){
                count--;
            }
            freq[s[j]]--;
            j++;

            while(count==0){
                if(j-i<length){
                    length=j-i;
                    start=i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        if(length!=INT_MAX) return s.substr(start,length);
        return "";
    }
};
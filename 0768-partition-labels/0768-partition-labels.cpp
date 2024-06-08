class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> letters(26,0);

        for(int i=0;i<s.size();i++)
            letters[s[i]-'a']=i;
        
        int i=0,j=0;
        vector<int> ans;
        for(int k=0;k<s.size();k++){
            j=max(j,letters[s[k]-'a']);
            if(k==j){
                ans.push_back(j-i+1);
                i=j+1;
            }
        }
        return ans;
    }
};


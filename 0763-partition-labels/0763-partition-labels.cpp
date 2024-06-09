class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> index(26,0);
        int n=s.size();
        //store rightmist index of each letter in string
        for(int i=0;i<n;i++){
            index[s[i]-'a']=i;
        }
        //calculate length of each group
        int l=0,r=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            r=max(index[s[i]-'a'],r);
            if(i==r){
                ans.push_back(r-l+1);
                l=r+1;
            }
        }
        return ans;
    }
};
class Solution {
  
public:
    int help(int i, string& s,unordered_set<string>& st, string temp){
        if(i==s.size())
            return 0;
        else{
            int n1=-10000,n2=-10000,ans;
            temp+=s[i];
            if(st.count(temp)==0){
                
                st.insert(temp);
                n1=1+help(i+1,s,st,"");
                st.erase(temp);
            }
            n2=help(i+1,s,st,temp);
            ans=max(n1,n2);
            return ans;
        }
    }
    int maxUniqueSplit(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(s.size()==0 || s.size()==1)
            return s.size();
        unordered_set<string> st;
        return help(0,s,st,"");
    }
};
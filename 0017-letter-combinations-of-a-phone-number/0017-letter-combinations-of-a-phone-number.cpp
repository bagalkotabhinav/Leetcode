class Solution {
public:
    void solve(string digits, vector<string>& ans, int index, string temp, vector<string>& map){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit=digits[index]-'0';
        string key=map[digit];
        for(int i=0;i<key.size();i++){
            temp.push_back(key[i]);
            solve(digits,ans,index+1,temp,map);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> ans;
        if(digits.size()==0)
            return ans;
       vector<string> num ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,0,"",num);
        return ans;
    }
};


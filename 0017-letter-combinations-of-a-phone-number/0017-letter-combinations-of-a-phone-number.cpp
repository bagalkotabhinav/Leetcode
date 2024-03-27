class Solution {
public:
    void init(vector<string>& mp){
        mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    }
    void solve(int index, string& digits, vector<string>& mp, vector<string>& ans, string& temp){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string comb=mp[digits[index]-'0'];

        for(auto i: comb){
            temp.push_back(i);
            solve(index+1,digits,mp,ans,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>mp;
        init(mp);
        vector<string> ans;
        if(digits=="")
            return ans;
        string temp="";
        solve(0,digits,mp,ans,temp);
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        stack<char> bracket;
        
        for( auto i: s){
            if(i=='(' || i=='{' || i=='[')
                bracket.push(i);
            else{
                if(bracket.empty() || (bracket.top()=='(' && i!=')') || (bracket.top()=='[' && i!=']') || (bracket.top()=='{' && i!='}'))
                    return false;
                bracket.pop();
            }
        }
        return bracket.empty();
    }
};

//if opening bracket, push in stack
//if closing bracket: pop
//if popped value is not equal to closing bracket type, return false

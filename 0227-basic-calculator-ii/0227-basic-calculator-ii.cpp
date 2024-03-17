class Solution {
public:
    int calculate(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int temp=0,ans=0,cur;
        char prevsign='+';
        stack<int> num;

        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                temp=10*temp+(int(s[i])-48);
            if(!isdigit(s[i]) && s[i]!=' ' || i==s.size()-1){
                if(prevsign=='-'){
                    num.push(-temp);
                }
                else if(prevsign=='+'){
                    num.push(temp);
                }
                else{
                    if(prevsign=='*'){
                        cur=num.top();
                        num.pop();
                        num.push(cur*temp);
                    }
                    else{
                        cur=num.top();
                        num.pop();
                        num.push(cur/temp);
                    }
                }
                prevsign=s[i];
                temp=0;
            }
        }



        while(!num.empty()){
            ans=ans+num.top();
            num.pop();
        }

        return ans;
    }
};
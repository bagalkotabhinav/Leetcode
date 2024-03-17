class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        stack<int> st;
        int n1=0,n2=0,n3=0;
        for(auto i: tokens){
            
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                n1=st.top();
                st.pop();
                n2=st.top();
                st.pop();
                if(i=="+"){
                    n3=n2+n1;
                }
                else if(i=="-"){
                    n3=n2-n1;
                }
                else if(i=="*"){
                    n3=n2*n1;
                }
                else{
                    n3=n2/n1;
                }
                st.push(n3);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
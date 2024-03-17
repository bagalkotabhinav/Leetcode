class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=t.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && t[st.top()]<t[i]){
                int temp=st.top();
                ans[temp]=i-temp;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

















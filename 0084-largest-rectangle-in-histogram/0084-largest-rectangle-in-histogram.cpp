class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=heights.size();
        stack<int> st;
        int maxht=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int ht=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                maxht=max(maxht,ht*width);
            }
            st.push(i);
        }
        return maxht;
    }
};
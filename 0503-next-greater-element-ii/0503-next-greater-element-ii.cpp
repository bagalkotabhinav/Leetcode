class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        // ||4 3 2 1 
        for(int i=n-1;i>=0;i--)
            st.push(nums[i]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top())
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>st.top())
                st.pop();

            if(st.empty())
                mp.insert({nums2[i],-1});
            
            else
                mp.insert({nums2[i],st.top()});
            
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i: nums1)
            ans.push_back(mp[i]);
        return ans;
    }
};

// piche se keep pushing elements in stack
// at first push last ele, and assign -1
// if cur ele in nums2>stack top, pop all less elements and push current element
// else if cur ele in nums2<stack top, push and set nextg as stack top

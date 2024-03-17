class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        vector<int> res;
        deque<int> dq;
        while(j<nums.size()){
            //DQ DECREASING: HENCE DELETE ALL ELEMENTS LESSER THAN CUR
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
            if(j>=k){
                res.push_back(nums[dq.front()]);
                i++;
            }
            if(i>dq.front()){
                dq.pop_front();
            }
        }
        return res;
    }
};
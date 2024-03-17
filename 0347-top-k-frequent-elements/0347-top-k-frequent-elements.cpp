class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> freq;
        for(auto i: nums){
            freq[i]++;
        }

        vector<pair<int,int>> num;

        for(auto i: freq){
            num.push_back({i.second,i.first});
        }

        sort(num.rbegin(),num.rend());

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(num[i].second);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto i: arr1)
            mp[i]++;
        vector<int> ans;
        int i=0;
        while(i<arr2.size()){
            if(mp[arr2[i]]){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            else
                i++;
        }
        for(auto i: mp){
            for(int j=0;j<i.second;j++)
                ans.push_back(i.first);
            mp.erase(i.first);
        }
            
        return ans;
    }
};

// 2 3
// 1 1
// 4 1
// 3 2
// 9 1
// 6 1
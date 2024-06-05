class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        unordered_set<int> num;
        for(int i=0;i<n;i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])
                continue;
            for(int j=0;j<3;j++){
                if(triplets[i][j]==target[j])
                    num.insert(j);
            }
        }
        return num.size()==3;
    }
};
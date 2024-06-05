class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& a, vector<int>& b) {
        int n=a.size();
        unordered_set<int> k;
        for(int i=0;i<n;i++){
            if(a[i][0]>b[0] || a[i][1]>b[1] || a[i][2]>b[2])
                continue;
            for(int j=0;j<3;j++){
                if(a[i][j]==b[j])
                    k.insert(j);
            }
        }
        return k.size()==3;
    }
};
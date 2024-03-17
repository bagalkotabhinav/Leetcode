class Solution {
public:
    bool AP(vector<int>& sub){
        int d=sub[1]-sub[0];
        for(int i=2;i<sub.size();i++){
            if(sub[i]-sub[i-1]!=d)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<bool> ans;
        int n=nums.size();
        int m=l.size();

        for(int i=0;i<m;i++){
            int n1=l[i];
            int n2=r[i];
            vector<int> sub(nums.begin()+n1,nums.begin()+n2+1);


            sort(sub.begin(),sub.end());
            bool subans=AP(sub);
            ans.push_back(subans);
        }
        return ans;
    }
};
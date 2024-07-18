class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto i: asteroids){
            if(i>0)
                ans.push_back(i);
            else{
                while(!ans.empty() && ans.back()>0 && ans.back()<-i)
                    ans.pop_back();
                if(!ans.empty() && ans.back()==-i)
                    ans.pop_back();
                else if(ans.empty() || ans.back()<0)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,vector<int>> mp;
        vector<int> is_a_prerequisite(numCourses,0);
        for(auto i: prerequisites){
            mp[i[0]].push_back(i[1]);
            is_a_prerequisite[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!is_a_prerequisite[i])
                q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto i: mp[temp]){
                is_a_prerequisite[i]--;
                if(!is_a_prerequisite[i])
                    q.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses)
            return {};
        return ans;
    }
};
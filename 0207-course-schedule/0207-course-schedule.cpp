class Solution {
public:
    bool cycle(int course, unordered_map<int,vector<int>>& mp, unordered_set<int>& visited){
        if(visited.find(course)!=visited.end())
            return true;
        visited.insert(course);
        for(int i=0;i<mp[course].size();i++){
            if(cycle(mp[course][i],mp,visited))
                return true;
        }
        visited.erase(course);
        mp[course].clear();
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1 || prerequisites.size()==0) return true;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<prerequisites.size();i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visited;
        for(int i=0;i<numCourses;i++){
            if(cycle(i,mp,visited))
                return false;
        }
        return true;
    }
};

// 1->2 3 4
// 2->3 5
// 4->1
// bottom layer visited allowed, upper layer visited not allowed
// clear course map which does not provide cycle 
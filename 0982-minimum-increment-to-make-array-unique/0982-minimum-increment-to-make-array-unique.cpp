class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> mp;
        for(auto i: nums)
            mp[i]++;
        int ans=0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            int freq=it->second;
            if(freq>1){
                mp[it->first+1]+=freq-1;
                ans+=freq-1;
            }
        }
        return ans;
    }
};
/*
1->2
2->2
3->1
7->1
1

1->1
2->3
3->1
7->1
2

1->1
2->1
3->3
7->1
2

1->1
2->1
3->1
4->2
7->1
1

1->1
2->1
3->1
4->1
5->1
7->1

start from beginning. reduce count to 1. count difference of cur count and 1. add that to ans
by this number, increase count of next consecutive element
do this till end of map
*/
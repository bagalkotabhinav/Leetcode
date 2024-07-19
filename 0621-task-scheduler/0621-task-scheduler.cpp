class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> pq;
        queue<pair<int,int>> q;

        for(auto i: tasks)
            freq[i-'A']++;
        
        for(auto i: freq){
            if(i)
                pq.push(i);
        }

        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            
            if(!pq.empty()){
                if(pq.top()-1)
                    q.push({pq.top()-1,time+n});
                pq.pop();
            }

            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
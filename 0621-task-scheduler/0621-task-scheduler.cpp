class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> pq;
        queue<vector<int>> q;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i])
                pq.push(freq[i]);
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                if(pq.top()-1)
                    q.push({pq.top()-1,time+n});
                pq.pop();
            }
            if(!q.empty() && q.front()[1]==time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
    }
};

//make a max heap to store frequencies of elements in the input
//make a queue of 2 element vector to store new freq of that element and the time when that element can be processed
//pop top ele of maxheap
//time++
//store {top ele-1,newtime} in queue
//newtime=time+n
//if q.front[1], ie time when that ele is to be processed==time, then rempve the element from queue
//push q.front[0], ie freq of that element in maxheap
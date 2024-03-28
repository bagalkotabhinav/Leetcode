class Solution {
private:
    priority_queue<int> pq;
public:
    int solve(priority_queue<int>& pq){
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(y>x){
                pq.push(y-x);
            }
        }
        if(!pq.size())
            return 0;
        return pq.top();
    }
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        for(auto i: stones)
            pq.push(i);
        return solve(pq);
    }
};

//2 top ele in max heap
//if both same val, pop both
//else pop smaller one and push number=big-small
//do till heap size=1
//return top
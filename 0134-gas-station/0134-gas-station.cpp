class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totgas=0,totcost=0;

        for(int i=0;i<n;i++){
            totgas+=gas[i];
            totcost+=cost[i];
        }
        
        if(totgas<totcost)
            return -1;
        
        int curgas=0,ans=0;

        for(int i=0;i<n;i++){
            curgas+=gas[i]-cost[i];
            if(curgas<0){
                curgas=0;
                ans=i+1;
            }
        }
        return ans;
    }
};
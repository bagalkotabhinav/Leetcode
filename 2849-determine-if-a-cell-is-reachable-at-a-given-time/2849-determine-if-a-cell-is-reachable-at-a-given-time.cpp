class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(sx==fx && sy==fy){
            if (t==1)
                return false;
        }
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        int ans=max(x,y);
        return(ans<=t);
    }
};
class Solution {
public:
    int maxArea(vector<int>& h) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int area=0;
        int n=h.size();
        int i=0,j=n-1;
        while(i<j){
            int curarea=(j-i)*min(h[i],h[j]);
            area=max(area,curarea);
            if(h[i]<h[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return area;
    }
};

//area=(i1-i0)*min(h1,h0)
//if left height is lesser, increment left pointer
//if right height is lesser, increment right pointer
//if same, increment that pointer whose next height is more
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max=0,sum=0;
        vector<int> alt;
        // alt.push_back(0);
        for(int i=0;i<gain.size();i++){
            
            alt.push_back(sum);
            sum=sum+gain[i];
            // if(sum>max){
            //     max=sum;
            // }
        }
        alt.push_back(sum);
        return *max_element(alt.begin(),alt.end());
    }
};
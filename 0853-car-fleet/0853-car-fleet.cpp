class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //sort cars based on positions, nearer or farther than target
        //calculate time for each car
        //if nearest car needs more time than farther car, they will merge, and farther will move at speed of nearer
        //assume number of fleets to be n, and if a nearer car travels slower, it will merge and fleets be one less 
        
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=speed.size();
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        vector<float> time(n);
        for(int i=0;i<n;i++){
            time[i]=(float)(target-cars[i].first)/cars[i].second;
        }
        int ans=n;
        for(int i=n-1;i>0;i--){
            if(time[i]>=time[i-1]){
                time[i-1]=time[i];
                ans--;
            }
        }
        return ans;
    }
};
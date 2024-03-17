class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        vector<int> ans;
        int i=0;
        int j=numbers.size()-1;

        while(i<j){
            if((numbers[i]+numbers[j])==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if((numbers[i]+numbers[j])<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};        
    }
};

//i to 1st number
//j to last number
//if j more than target, j--
//j reach a index which is just smaller than target
//do i+j. if target, return indices of i and j
//if i+j>target j--
//if i+j<target i++

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string range;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(range.size()==0){
                if(i==nums.size()-1){
                    string temp;
                    int num=nums[i];
                    temp=to_string(num);
                    range=range+temp;
                    ans.push_back(range);
                    break;
                }
                int num=nums[i];
                range=to_string(num);

            }
            // int diff=nums[i+1]-nums[i];

            if(nums[i+1]==nums[i]+1){
                if(i+1==nums.size()-1){
                    string temp;
                    range.push_back('-');
                    range.push_back('>');
                    int num=nums[i+1];
                    temp=to_string(num);
                    range=range+temp;
                    ans.push_back(range);
                    break;
                }   
                count++;
            }

            else{
                if(count>0){
                    string temp;
                    range.push_back('-');
                    range.push_back('>');
                    int num=nums[i];
                    temp=to_string(num);
                    range=range+temp;
                    ans.push_back(range);
                    range.clear();
                    temp.clear();
                    count=0;
                }
                else{
                   
                    ans.push_back(range);
                    range.clear();
                }
                
            }

        }
        return ans;
    }
};
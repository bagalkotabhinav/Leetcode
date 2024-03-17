class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        if(nums.size()==0)
            return 0;
        //REACH MINIMUM VALUE OF CURRENT CONSECUTIVE SUBSEQUENCE AND CHECK PRESENCE OF HIGHER CONSECUTIVE ELEMENTS
        unordered_set<int> num(nums.begin(),nums.end());
        int maxans=1;
        for(auto it: num){
            if(num.find(it-1)==num.end()){
                int ans=1;
                int curnum=it;
                while(num.find(curnum+1)!=num.end()){
                    curnum=curnum+1;
                    ans=ans+1;
                }
                maxans=max(ans,maxans);
            }
        }
        return maxans;
    }
};


// class Solution {
// public:
        //FROM CURRENT ELEMENT IN SET, CHECK PRESENCE OF ALL THE NEXT AND PREVIOUS ELEMENTS AND ERASE THE CURRENT, ALL THE NEXT AND PREVIOUS ELEMENTS
//     int longestConsecutive(vector<int>& nums) {
//         ios_base::sync_with_stdio(false); cin.tie(NULL);
//         if(nums.size()==0)
//             return 0;
//         unordered_set<int> num(nums.begin(),nums.end());
//         int max1=1,max2=1,start,temp;

//         while(num.size()>0){
//             max1=1;
//             start=*(num.begin());
//             num.erase(start);
//             temp=start+1;
//             while(num.count(temp)){
//                 max1++;
//                 num.erase(temp);
//                 temp++;
//             }
//             temp=start-1;
//             while(num.count(temp)){
//                 max1++;
//                 num.erase(temp);
//                 temp--;
//             }
//             max2=max(max1,max2);
//         }
//         return max2;
//     }
// };
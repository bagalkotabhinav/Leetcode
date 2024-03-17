class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int len=arr.size(),index;
        for(int i=len/2;i>=0,i<=len-1;){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                index=i;
                break;
            }
            if(arr[i]<arr[i-1])
                i--;
            else if(arr[i]<arr[i+1])
                i++;
        }
        return index;
    }
};
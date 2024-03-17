class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);

        int i=0;
        int j=m;
        int total=m+n;
        double ans=0.0;
        while(i<=j){
            int smid=i+(j-i)/2;
            int r1=(smid<m)?nums1[smid]:INT_MAX;
            int l1=(smid>0)?nums1[smid-1]:INT_MIN;

            int lmid=(total+1)/2 -smid;
            int r2=(lmid<n)?nums2[lmid]:INT_MAX;
            int l2=(lmid>0)?nums2[lmid-1]:INT_MIN;

            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                    ans=(max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                    ans=max(l1,l2);
                return ans;
            }
            else if(l2>=r1)
                i=smid+1;
            else
                j=smid-1;
        }
        return ans;
    }
};
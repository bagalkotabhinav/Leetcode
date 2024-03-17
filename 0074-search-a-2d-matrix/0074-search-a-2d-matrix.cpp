class Solution {
public:
    vector<int> rowsearch(vector<vector<int>>& matrix, int target, int srow, int erow){
        if(srow<=erow){
            int mid=(srow+erow)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1])
                return matrix[mid];
            else if(target<matrix[mid][0])
                return rowsearch(matrix,target, srow, mid-1);
            else
                return rowsearch(matrix,target,mid+1,erow);
        }
        return {}; 
    }
    bool ans(vector<vector<int>>& matrix, int target){
        vector<int> ans=rowsearch(matrix,target,0,matrix.size()-1);
        int i=0,j=ans.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(target==ans[mid])
                return true;
            else if(target>ans[mid]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        return ans(matrix,target);
    }
};
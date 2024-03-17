class Solution {
public:
    string getPermutation(int n, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        k=k-1;
        string ans;
        int size,batch_size,batch_no,num;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int factorial[10]={1,1,2,6,24,120,720,5040,40320,362880};
        while(arr.size()>0){

            size=arr.size();
            batch_size=factorial[size]/size;
            batch_no=k/batch_size; 

            num=arr[batch_no];
            ans.push_back(char(num)+48);

            k=k%batch_size;
            arr.erase(arr.begin()+batch_no);
        }
        return ans;
    }
};

//if n=4, K=9-1=8 (0 indexing)
//arr= [1,2,3,4]
//1 (234) B1
//2 (134) B2
//3 (124) B3
//4 (123) B4
//batch size=4!/4=6
//batch no=k/batch_size: 8/6=2
//number=arr[batch_no]=arr[2]=3: append 3 in ans

//reduce k=k%batch_size
// reduce arr bu deleting 3, ie arr[2], ie arr.erase(arr.begin()+batch_no)

//recursion till size is 0
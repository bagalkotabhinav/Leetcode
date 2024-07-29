/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp){
        if(root==NULL)
            return;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j){
            int sum=ans[i]+ans[j];
            if(sum==k)
                return true;
            else if(sum<k)
                i++;
            else
                j--;
        }
        return false;
    }
};

// 2 3 4 5 6 7

// 2 3 4 5 6 7
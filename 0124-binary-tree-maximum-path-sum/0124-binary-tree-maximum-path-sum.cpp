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
    int solve(TreeNode* root, int& maxi){
        if(root==NULL)
            return 0;
        int lst=max(solve(root->left,maxi),0);
        int rst=max(solve(root->right,maxi),0);
        maxi=max(maxi,root->val+lst+rst);
        return root->val+max(lst,rst);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN/2;
        int a=solve(root,maxi);
        return maxi;
    }
};
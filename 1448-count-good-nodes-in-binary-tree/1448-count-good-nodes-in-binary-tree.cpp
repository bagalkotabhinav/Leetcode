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
    int solve(TreeNode* root, int count, int curmax){
        if(root==NULL)
            return 0;
        if(root->val>=curmax)
            count=1;
        else
            count=0;
        curmax=max(curmax,root->val);
        count+=solve(root->left,count,curmax);
        count+=solve(root->right,count,curmax);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        return solve(root,count,root->val);
    }
};

//dfs(preorder) traversal, and compare curmax with root->val
//if root->val<curmax, not a good node
//if root->val>=curmax, good node
    // curmax=root->val (pass root->val in place of curmax)
    //do count++
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
    int solve(TreeNode* root, int& ans){
        if(root==nullptr)
            return 0;
        int lst=max(solve(root->left,ans),0);
        int rst=max(solve(root->right,ans),0);
        ans=max(ans,root->val+lst+rst);
        return root->val+max(lst,rst);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN/2;
        solve(root,ans);
        return ans;
    }
};
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
    bool issame(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr || q==nullptr)
            return false;
        if(p->val==q->val)
            return (issame(p->left,q->left) && issame(p->right,q->right));
        return false;     
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(subRoot==nullptr)
            return true;
        if(root==nullptr)
            return false;
        if(issame(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};

//if root==subroot, true
//if not, root.left and subroot check, root.right and subroot check
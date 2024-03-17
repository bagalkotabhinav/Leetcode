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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(i>j)
            return NULL;
        TreeNode* root= new TreeNode(preorder[index]);

        int split;
        for(int i=0;i<inorder.size();i++){
            if(preorder[index]==inorder[i]){
                split=i;
                break;
            }
        }
        index++;

        root->left=solve(preorder,inorder,index,i,split-1);
        root->right=solve(preorder,inorder,index,split+1,j);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int index=0;
        return solve(preorder,inorder,index,0,inorder.size()-1);
    }
};
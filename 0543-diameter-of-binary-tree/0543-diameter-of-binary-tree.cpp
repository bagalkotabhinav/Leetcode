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
    int depth(TreeNode* root , int& diameter){
        if(root==nullptr)
            return 0;
        int left_maxdepth=depth(root->left,diameter);
        int right_maxdepth=depth(root->right,diameter);
        diameter=max(diameter,left_maxdepth+right_maxdepth);
        return 1+max(left_maxdepth,right_maxdepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        depth(root,diameter);
        return diameter;
    }
};


//Diameter=any node to any node max nodes covered
//diameter=farthest node to left+farthest node to right+1
//calc depth for left subtree as it will give farthest node to left
//calc depth for right subtree as it will give farthest node to right
//return left+right+1
//this is diameter, passing thru root
//pass this function recursively, and maintain max diameter
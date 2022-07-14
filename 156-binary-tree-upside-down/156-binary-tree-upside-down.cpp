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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root or (!root->left and !root->right))
            return root;
        TreeNode *newRoot = upsideDownBinaryTree(root->left);
        
        root->left->left = root->right;
        root->left->right = root;
        root->left = NULL;
        root->right = NULL;
        return newRoot;
    }
};
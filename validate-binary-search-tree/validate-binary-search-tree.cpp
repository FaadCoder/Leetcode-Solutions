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
    bool isValidBSTHelper(TreeNode *root,TreeNode *&prev)
    {
        if(!root)
            return true;
        if(!isValidBSTHelper(root->left,prev))
            return false;
        if(prev and root->val<=prev->val)
            return false;
        prev = root;
        
        return isValidBSTHelper(root->right,prev);
    }
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode *prev = NULL;
        return isValidBSTHelper(root,prev);
    }
};
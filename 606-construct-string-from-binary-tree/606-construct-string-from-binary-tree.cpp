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

    string getString(TreeNode *root)
    {
        if(!root)
            return "";
        
        if(!root->left and !root->right)
            return to_string(root->val);
        
        string leftSubtree = getString(root->left);
        string rightSubtree = getString(root->right);
        
        string str = to_string(root->val) + "(" + leftSubtree + ")" ;
        
        if(!rightSubtree.empty())
            str += "(" + rightSubtree + ")";

        return str;
    }
    
    public:
    string tree2str(TreeNode* root) {
        return getString(root);
    }
};
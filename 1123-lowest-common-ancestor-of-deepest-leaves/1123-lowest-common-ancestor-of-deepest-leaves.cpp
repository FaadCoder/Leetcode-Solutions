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
    // pair<Node,Height>
    pair<TreeNode *,int> getLCA(TreeNode *root)
    {
        if(!root)
            return {nullptr,0};
        auto left = getLCA(root->left);
        auto right = getLCA(root->right);
        
        TreeNode* leftLCA = left.first;
        TreeNode* rightLCA = right.first;
        
        int leftHeight = left.second;
        int rightHeight = right.second;
        
        if(leftHeight > rightHeight)
            return {leftLCA,leftHeight+1};
        else if(leftHeight < rightHeight)
            return {rightLCA,rightHeight+1};
        else
            return {root,leftHeight+1};
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return nullptr;
        return getLCA(root).first;
    }
};
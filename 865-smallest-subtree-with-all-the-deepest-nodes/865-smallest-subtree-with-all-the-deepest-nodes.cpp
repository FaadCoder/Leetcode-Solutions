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
    pair<int, TreeNode *> getSubtree(TreeNode *root)
    {
        if(!root)
            return {0, NULL};
        auto left = getSubtree(root->left);
        auto right = getSubtree(root->right);
        
        int leftSubtreeDepth = left.first;
        int rightSubtreeDepth = right.first;
        
        TreeNode *leftSubtree = left.second;
        TreeNode *rightSubtree = right.second;
        
        if(leftSubtreeDepth == rightSubtreeDepth)
            return {leftSubtreeDepth + 1, root};
        else if(leftSubtreeDepth > rightSubtreeDepth)
            return {leftSubtreeDepth + 1, leftSubtree};
        else
            return {rightSubtreeDepth + 1, rightSubtree};
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        
        return getSubtree(root).second;
        
    }
};
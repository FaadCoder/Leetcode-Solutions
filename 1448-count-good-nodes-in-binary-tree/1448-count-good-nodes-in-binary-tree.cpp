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
    int goodNodes(TreeNode* root, int maxNode = INT_MIN) {
        if(!root)
            return 0;
        int goodNodesFromLeft = goodNodes(root->left, max(root->val, maxNode));
        int goodNodesFromRight = goodNodes(root->right, max(root->val, maxNode));
        
        return goodNodesFromLeft + goodNodesFromRight + (root->val >= maxNode);
        
    }
};
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
    
    int maxStep = 0;
    
    void getLongestPath(TreeNode *root, bool isLeft, int step)
    {
        if(!root)
         return;
        
        maxStep = max(maxStep, step);
        
        if(isLeft)
        {
            getLongestPath(root->left, false, step + 1);
            getLongestPath(root->right, true, 1);
        }
        else
        {
            getLongestPath(root->right, true, step + 1);
            getLongestPath(root->left, false, 1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        maxStep = 0;
        getLongestPath(root, false, 0);
        getLongestPath(root, true, 0);
        return maxStep;
    }
};
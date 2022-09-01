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

    int maxLength = 0;
    
    int calculateLongestConsecutiveLength(TreeNode *root)
    {
        if(!root)
            return 0;
    
        int leftSubtree = calculateLongestConsecutiveLength(root->left) + 1;
        int rightSubtree = calculateLongestConsecutiveLength(root->right) + 1;
        
        if(root->left and (root->left->val - 1) != root->val)
            leftSubtree = 1;
        
        if(root->right and (root->right->val - 1) != root->val)
            rightSubtree = 1;
        
        int length = max(leftSubtree, rightSubtree);
        maxLength = max(maxLength, length);
        
        return length;
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        calculateLongestConsecutiveLength(root);
        return maxLength;
        
    }
};
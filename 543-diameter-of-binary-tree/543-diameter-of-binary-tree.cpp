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
    int computeDiameterOfBinaryTree(TreeNode *root,int &ans)
    {
        if(!root)
            return 0;
        int leftHeight = computeDiameterOfBinaryTree(root->left,ans);
        int rightHeight = computeDiameterOfBinaryTree(root->right,ans);
        ans = max(ans,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        computeDiameterOfBinaryTree(root,ans);
        return ans;
    }
};
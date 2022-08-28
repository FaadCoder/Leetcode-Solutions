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
    int leftCount = 0, rightCount = 0;
    
    int count(TreeNode *root, int x)
    {
        if(!root)
            return 0;
        
        int left = count(root->left, x);
        int right = count(root->right, x);
        
        if(root->val == x)
            leftCount = left, rightCount = right;
        
        return left + right + 1;
    }
    
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);
        int maxCount = max({leftCount, rightCount, n - leftCount - rightCount - 1});
        return (maxCount > (n>>1));
    }
};
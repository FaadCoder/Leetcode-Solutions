/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    unordered_map<TreeNode *, int> dp;
    
    public:
        int rob(TreeNode *root)
        {
            if (!root)
                return 0;
            
            if(dp.count(root))
                return dp[root];
            
            int left = rob(root->left);
            int right = rob(root->right);
            
            int curr =  root->val + ((root->left) ? rob(root->left->left) + rob(root->left->right) : 0 ) + ((root->right) ? rob(root->right->left) + rob(root->right->right) : 0);
            
            return dp[root] = max(curr, left + right);
            
        }
};
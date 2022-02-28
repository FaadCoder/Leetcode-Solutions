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
    int computeMaxPathSum(TreeNode *root,int &ans)
    {
        if(!root)
            return 0;
        int leftPathSum = max(0,computeMaxPathSum(root->left,ans));
        int rightPathSum = max(0,computeMaxPathSum(root->right,ans));
        ans = max(ans,root->val+leftPathSum+rightPathSum);
        return (root->val + max(leftPathSum,rightPathSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int ans = INT_MIN;
        computeMaxPathSum(root,ans);
        return ans;
    }
};

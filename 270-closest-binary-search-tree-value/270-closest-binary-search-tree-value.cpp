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
    double ans = INT_MIN/2;
    
    void getClosestValue(TreeNode *root,double target)
    {
        if(!root)
            return;
        if(root->val>target)
            getClosestValue(root->left,target);
        else
            getClosestValue(root->right,target);
        if(abs(target-ans)>abs(target-root->val))
            ans = root->val;
    }
    
public:
    int closestValue(TreeNode* root, double target) 
    {
        getClosestValue(root,target);
        return ans;
    }
};
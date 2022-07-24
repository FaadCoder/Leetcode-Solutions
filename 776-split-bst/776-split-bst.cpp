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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode *> roots(2,NULL);
        if(!root)
            return roots;
        if(root->val<=target)
        {
            roots[0] = root;
            auto split = splitBST(root->right,target);
            root->right = split[0];
            roots[1] = split[1];
        }
        else
        {
            roots[1] = root;
            auto split = splitBST(root->left,target);
            root->left = split[1];
            roots[0] = split[0];
        }
        return roots;
    }
};
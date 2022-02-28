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
    TreeNode *getBSTFromPreorder(vector<int>& preorder,int &idx,int upperBound)
    {
        if(idx>=preorder.size() or preorder[idx]>upperBound)
            return NULL;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = getBSTFromPreorder(preorder,idx,root->val);
        root->right = getBSTFromPreorder(preorder,idx,upperBound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        if(preorder.empty())
            return NULL;
        int idx=0;
        return getBSTFromPreorder(preorder,idx,INT_MAX);
    }
};
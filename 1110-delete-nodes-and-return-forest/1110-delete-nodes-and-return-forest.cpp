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
    vector<TreeNode *> forest;
    unordered_set<int> vis;
    void deleteNode(TreeNode *&root)
    {
        if(!root)
            return;
        deleteNode(root->left);
        deleteNode(root->right);
        if(vis.count(root->val))
        {
            if(root->left)
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);
            root = NULL;
        }
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vis = unordered_set<int>(begin(to_delete),end(to_delete));
        deleteNode(root);
        if(root)
            forest.push_back(root);
        return forest;
    }
};
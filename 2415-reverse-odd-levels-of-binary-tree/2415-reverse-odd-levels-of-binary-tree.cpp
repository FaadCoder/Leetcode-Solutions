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
    
    unordered_map<int, vector<int>> level;
    
    void dfs(TreeNode *root, int lvl = 0)
    {
        if(!root)
            return;
        if(lvl & 1)
            level[lvl].push_back(root->val);
        dfs(root->left, lvl+1);
        dfs(root->right, lvl+1);
    }
    
    void fillLevels(TreeNode *root, int lvl = 0)
    {
        if(!root)
            return;
        if(lvl & 1)
        {
            vector<int> &temp = level[lvl];
            root->val = temp.back();
            temp.pop_back();
        }
        fillLevels(root->left, lvl+1);
        fillLevels(root->right, lvl+1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root);
        fillLevels(root);
        return root;
    }
};
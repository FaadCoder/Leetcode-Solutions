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
    vector<vector<int>> paths;
    vector<int> currentPath;
    
    bool isLeafNode(TreeNode *root)
    {
        return (!root->left and !root->right);
    }
    
    void populateAllPathsWithSum(TreeNode *root, int targetSum)
    {
        if(!root)
            return;
        
        currentPath.push_back(root->val);
        
        if(isLeafNode(root) and targetSum == root->val)
        {
            paths.push_back(currentPath);
        }
        
        populateAllPathsWithSum(root->left, targetSum - root->val);
        populateAllPathsWithSum(root->right, targetSum - root->val);
        
        currentPath.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        paths.clear();
        currentPath.clear();
        
        populateAllPathsWithSum(root, targetSum);
        
        return paths;
    }
};
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
    
    vector<vector<int>> leaves;
    
    int populateLeaves(TreeNode *root)
    {
        if(!root)
            return -1;
        
        int leftHeight = populateLeaves(root->left);
        int rightHeight = populateLeaves(root->right);
        int currentHeight = 1 + max(leftHeight,rightHeight);
        
        if(leaves.size() == currentHeight)
            leaves.push_back({});
        
        leaves[currentHeight].push_back(root->val);
        
        return currentHeight;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        populateLeaves(root);
        return leaves;
    }
};
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
    unordered_map<int,int> heightMap;
    int maxLevel = 0;
    
    void populateHeightMap(TreeNode *root, int level = 0)
    {
        if(!root)
            return; 
        
        heightMap[root->val] = level;
        maxLevel = max(maxLevel, level);
        
        populateHeightMap(root->left, level + 1);
        populateHeightMap(root->right, level + 1);
    }
    
    TreeNode *ans;
    
    int getSubtree(TreeNode *root, int nodesAtMaxLevel)
    {
        if(!root)
            return 0;
        
        int left = getSubtree(root->left, nodesAtMaxLevel);
        int right = getSubtree(root->right, nodesAtMaxLevel);
        
        int currNodes = left + right + (heightMap[root->val] == maxLevel);
        
        if(currNodes == nodesAtMaxLevel)
        {
            ans = root;
            return 0;
        }
        return currNodes;
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        
        populateHeightMap(root);
        
        int nodesAtMaxLevel = 0;
        
        for(auto it:heightMap)
        {
            nodesAtMaxLevel += (it.second == maxLevel);
        }
        
        
         getSubtree(root, nodesAtMaxLevel);
        return ans;
        
    }
};
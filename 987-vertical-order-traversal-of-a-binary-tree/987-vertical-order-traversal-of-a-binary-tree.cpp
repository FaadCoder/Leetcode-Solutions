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
    map<int,map<int,multiset<int>>> traversal;
    
    void populateDistances(TreeNode *root,int level = 0, int currDis = 0)
    {
        if(!root)
            return;
        traversal[currDis][level].insert(root->val);
        populateDistances(root->left,level+1,currDis-1);
        populateDistances(root->right,level+1,currDis+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
        populateDistances(root);
        vector<vector<int>> ans;
        
        for(auto it1:traversal)
        {
            vector<int> temp;
            for(auto it2:it1.second)
            {
                for(auto num:it2.second)
                    temp.push_back(num);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};
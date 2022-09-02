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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> bfsQueue;
        
        vector<double> averages;
        bfsQueue.push(root);
        
        while(!bfsQueue.empty())
        {
            int sz = bfsQueue.size();
            double valAtLevel = 0;
            
            for(int node = 1; node <= sz; node++)
            {
                TreeNode *front = bfsQueue.front();
                bfsQueue.pop();
                valAtLevel += front->val;
                
                if(front->left)
                    bfsQueue.push(front->left);
                if(front->right)
                    bfsQueue.push(front->right);
            }
            
            averages.push_back(1.0 * valAtLevel / sz);
        }
        
        return averages;
    }
};
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
    unordered_map<int,vector<int>> distanceToNodesMap;
    int minDistance,maxDistance;
    
    void populateHorizontalDistances(TreeNode *root)
    {
        if(!root)
            return;
        
        queue<pair<int,TreeNode *>> bfsQueue;
        bfsQueue.push({0,root});
        
        while(!bfsQueue.empty())
        {
            int nodesAtCurrentLevel = bfsQueue.size();
            while(nodesAtCurrentLevel-->0)
            {
                auto [currentDistance, currNode] = bfsQueue.front();
                bfsQueue.pop();
                
                minDistance = min(minDistance, currentDistance);
                maxDistance = max(maxDistance, currentDistance);
                
                distanceToNodesMap[currentDistance].push_back(currNode->val);
                
                if(currNode->left)
                    bfsQueue.push({currentDistance-1, currNode->left});
                
                if(currNode->right)
                    bfsQueue.push({currentDistance+1, currNode->right});
                
            }
        }
        
    }
    
    vector<vector<int>> getVerticalOrder()
    {
        vector<vector<int>> verticalOrderStore;
        for(int dis = minDistance; dis<=maxDistance; dis++)
        {
            if(distanceToNodesMap[dis].size())
                verticalOrderStore.push_back(distanceToNodesMap[dis]);
        }
        
        return verticalOrderStore;
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        minDistance = INT_MAX;
        maxDistance = INT_MIN;
        
        populateHorizontalDistances(root);
        
        return getVerticalOrder();
    }
};
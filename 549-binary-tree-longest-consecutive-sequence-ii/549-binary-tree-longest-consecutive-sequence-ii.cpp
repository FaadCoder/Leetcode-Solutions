class Solution {
    
    int longestLen = 0;
    
    pair<int, int> consecutivePath(TreeNode *root)
    {
        if(!root)
            return {0,0};
        int increment = 1, decrement = 1;
        
        if(root->left)
        {
            auto leftSubtreePath = consecutivePath(root->left);
            if(root->val == root->left->val + 1)
                decrement = max(decrement, leftSubtreePath.second + 1);
            else if(root->val == root->left->val - 1)
                increment = max(increment, leftSubtreePath.first + 1);
        }
        
        if(root->right)
        {
            auto rightSubtreePath = consecutivePath(root->right);
            if(root->val == root->right->val + 1)
                decrement = max(decrement, rightSubtreePath.second + 1);
            else if(root->val == root->right->val - 1)
                increment = max(increment, rightSubtreePath.first + 1);    
        }
        
        longestLen = max(longestLen, increment + decrement - 1);
        
        return {increment, decrement};
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        consecutivePath(root);
        return longestLen;
    }
};
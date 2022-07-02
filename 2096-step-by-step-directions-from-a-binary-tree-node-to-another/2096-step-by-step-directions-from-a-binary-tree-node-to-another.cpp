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
    
    TreeNode *findLCS(TreeNode *root,int startValue,int destValue)
    {
        if(!root)
            return NULL;
        if(root->val == startValue or root->val==destValue)
            return root;
        
        TreeNode *left = findLCS(root->left,startValue,destValue);
        TreeNode *right = findLCS(root->right,startValue,destValue);
        
        if(left and right)
            return root;
        if(!left)
            return right;
        return left;
    }
    
    bool findLCSToValueDistanceString(TreeNode *lcsNode,int value,string &result)
    {
        if(!lcsNode)
            return false;
        
        if(lcsNode->val == value)
            return true;
        
        // Left
        result.push_back('L');
        if(findLCSToValueDistanceString(lcsNode->left,value,result))
            return true;
        result.pop_back();

        // Right
        result.push_back('R');
        if(findLCSToValueDistanceString(lcsNode->right,value,result))
            return true;
        result.pop_back();
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root)
            return "";
        TreeNode *lcsNode = findLCS(root,startValue,destValue);
        string lcsToStartDistanceString;
        findLCSToValueDistanceString(lcsNode,startValue,lcsToStartDistanceString);
        
        for(char &ch:lcsToStartDistanceString)
        {
            if(ch=='L' or ch=='R')
                ch = 'U';
        }
        
        string lcsToDestDistanceString;
        findLCSToValueDistanceString(lcsNode,destValue,lcsToDestDistanceString);
        
        return lcsToStartDistanceString + lcsToDestDistanceString;
    }
};
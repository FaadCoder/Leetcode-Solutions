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
    void recoverTreeHelper(TreeNode* root,TreeNode* &firstNode,TreeNode* &secondNode,TreeNode * &prev)
    {
        if(!root)
            return;
        recoverTreeHelper(root->left,firstNode,secondNode,prev);
        if(firstNode==NULL and prev->val > root->val)
            firstNode = prev;
        if(firstNode and prev->val > root->val)
            secondNode = root;
        prev = root;
        recoverTreeHelper(root->right,firstNode,secondNode,prev);
    }
public:
    void recoverTree(TreeNode* root) 
    {
        if(!root)
            return;
        TreeNode *firstNode = NULL;
        TreeNode *secondNode = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);
        recoverTreeHelper(root,firstNode,secondNode,prev);
        swap(firstNode->val,secondNode->val);
    }
};

// 1 2 3
// 3 2 1
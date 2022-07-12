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
    unordered_set<int> hashSet;
    TreeNode *nodeToRemove;
    void getNodeToRemove(TreeNode *root,TreeNode *prev)
    {
        if(!root)
            return;
        getNodeToRemove(root->right,root);
        if(hashSet.count(root->val))
        {
            nodeToRemove = prev;
            return;
        }
        hashSet.insert(root->val);
        getNodeToRemove(root->left,root);
    }
    
    TreeNode *removeNode(TreeNode* root,TreeNode* node)
    {
        if(!root)
            return NULL;
        root->left = removeNode(root->left,node);
        root->right = removeNode(root->right,node);
        if(root->val==node->val)
        {
            root->right = NULL;
            root = NULL;
        }
        return root;
    }
    
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        getNodeToRemove(root,NULL);
        return removeNode(root,nodeToRemove);
    }
};
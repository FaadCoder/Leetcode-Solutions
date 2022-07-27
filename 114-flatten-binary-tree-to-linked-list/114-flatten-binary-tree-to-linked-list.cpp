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
    
    TreeNode *flattenHelper(TreeNode* root)
    {
        if(!root)
            return NULL;
        
        TreeNode *leftFlattenSubtree = flattenHelper(root->left);
        TreeNode *rightFlattenSubtree = flattenHelper(root->right);
        
        root->left = NULL;
        root->right = NULL;
        
        root->right = leftFlattenSubtree;
        if(rightFlattenSubtree)
        {
            if(!leftFlattenSubtree)
                root->right = rightFlattenSubtree;
            else
            {
                TreeNode *ptr = leftFlattenSubtree;
                while(ptr->right)
                    ptr=ptr->right;
                ptr->right = rightFlattenSubtree;
            }
        }
        
        return root;
    }
    
public:
    void flatten(TreeNode* root) {
        root = flattenHelper(root);
    }
};
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
    void flatten(TreeNode* root) {
        while(root)
        {
            TreeNode *leftSubtree = root->left;
            TreeNode *rightSubtree = root->right;
            if(leftSubtree)
            {
                TreeNode *ptr = leftSubtree;
                while(ptr and ptr->right)
                    ptr=ptr->right;
                ptr->right = rightSubtree;
                root->left = NULL;
                root->right = leftSubtree;
            }
            root=root->right;
        }
    }
};
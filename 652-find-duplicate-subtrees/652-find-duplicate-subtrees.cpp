/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{

    // HashMap to keep track of inorder string.
    unordered_map<string,int> hashMap;
    
    // Vector to store duplicate subtrees nodes.
    vector<TreeNode *> duplicateSubtrees;
    
    // Method to find and populate all duplicate subtrees.
    string populateAllDuplicateSubtrees(TreeNode *root)
    {
        if(!root)
            return "";
        
        // Use parentheses to uniquely identify inorder traversal from current node.
        string inorderString = "(" + populateAllDuplicateSubtrees(root->left) + to_string(root->val) + populateAllDuplicateSubtrees(root->right) + ")";
        
        // If already seen the inorder traversal before.
        if(hashMap[inorderString] == 1)
            duplicateSubtrees.push_back(root);
        
        // increment the count.
        hashMap[inorderString]++;

        return inorderString;
    }

    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode *root)
        {
            populateAllDuplicateSubtrees(root);
            return duplicateSubtrees;
        }
};
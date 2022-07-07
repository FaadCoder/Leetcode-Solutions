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
class BSTIterator {
    queue<int> inorderTraversal;
    void storeInorderTraversal(TreeNode *root)
    {
        if(!root)
            return;
        storeInorderTraversal(root->left);
        inorderTraversal.push(root->val);
        storeInorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        storeInorderTraversal(root);
    }
    
    int next() {
        if(hasNext())
        {
            int nextNumber = inorderTraversal.front();
            inorderTraversal.pop();
            return nextNumber;
        }
        return -1;
    }
    
    bool hasNext() {
        return !inorderTraversal.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
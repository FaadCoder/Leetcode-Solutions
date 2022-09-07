/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{

    public:
        string tree2str(TreeNode *root)
        {
            if (!root)
                return "";

            string str = to_string(root->val);
            
            if (!root->left and!root->right)
                return str;

            string leftSubtree = tree2str(root->left);
            string rightSubtree = tree2str(root->right);
            str += "(" + leftSubtree + ")";
            
            if (!rightSubtree.empty())
                str += "(" + rightSubtree + ")";

            return str;
        }
};
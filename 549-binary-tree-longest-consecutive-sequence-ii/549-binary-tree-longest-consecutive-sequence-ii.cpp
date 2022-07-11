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
    pair<int,int> traverse(TreeNode *t, int &ans) {
    if (!t) return make_pair(0, 0);
    pair<int,int> left = traverse(t->left, ans);
    pair<int,int> right = traverse(t->right, ans);
    int inc=1, dec=1;
    if (left.first && t->left->val+1==t->val)
        inc = max(inc, left.first+1);
    if (right.first && t->right->val+1==t->val)
        inc = max(inc, right.first+1);
    if (left.second && t->left->val-1==t->val)
        dec = max(dec, left.second+1);
    if (right.second && t->right->val-1==t->val)
        dec = max(dec, right.second+1);
    ans = max(ans, inc+dec-1);
    return make_pair(inc, dec);
}
int longestConsecutive(TreeNode* root) {
    int ans = 0;
    traverse(root, ans);
    return ans;
}
};
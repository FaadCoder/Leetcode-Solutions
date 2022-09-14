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
    int res = 0;
    vector<int> hash;
    
    bool isPalindromic(vector<int> &temp)
    {
        int odds = 0;
        
        for(int i = 1; i<=9; i++)
            odds += (temp[i] % 2 == 1);
        
        return (odds <= 1);
    }
    
    void pseudoPalindromicPathsHelper (TreeNode* root) 
    {
        if(!root)
            return;
        
        hash[root->val] += 1;
        
        if(!root->left and !root->right)
        {
            if(isPalindromic(hash))
                res++;
        }
        
        pseudoPalindromicPathsHelper(root->left);
        pseudoPalindromicPathsHelper(root->right);
        hash[root->val] -= 1;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        hash.resize(10, 0);
        pseudoPalindromicPathsHelper(root);
        return res;
    }
};
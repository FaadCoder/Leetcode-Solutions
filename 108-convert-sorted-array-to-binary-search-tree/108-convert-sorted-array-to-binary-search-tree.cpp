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
    
    TreeNode *getHeightBalancedBST(vector<int> &nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        if(start == end)
            return new TreeNode(nums[start]);
        
        int midIdx = start + (end-start)/2;
        
        TreeNode *root = new TreeNode(nums[midIdx]);
        root->left = getHeightBalancedBST(nums, start, midIdx-1);
        root->right = getHeightBalancedBST(nums, midIdx+1, end);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getHeightBalancedBST(nums, 0, nums.size()-1);
    }
};
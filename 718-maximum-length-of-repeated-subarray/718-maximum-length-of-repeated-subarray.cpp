class Solution {
    
    int ans = 0;
    
    int getLongestRepeatedSubarrayLength(vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp, int nums1Idx = 0, int nums2Idx = 0)
    {
        if(nums1Idx >= size(nums1) or nums2Idx >= size(nums2))
            return 0;
        
        int &cachedValue = dp[nums1Idx][nums2Idx];
        
        if(cachedValue != -1)
            return cachedValue;
        
        getLongestRepeatedSubarrayLength(nums1, nums2, dp, nums1Idx + 1, nums2Idx);
        getLongestRepeatedSubarrayLength(nums1, nums2, dp, nums1Idx, nums2Idx + 1);

        if(nums1[nums1Idx] == nums2[nums2Idx])
            cachedValue = 1 + getLongestRepeatedSubarrayLength(nums1, nums2, dp, nums1Idx + 1, nums2Idx + 1);
        else
            cachedValue = 0;
        
        ans = max(ans, cachedValue);
        
        return cachedValue;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(size(nums1) + 1, vector<int>(size(nums2) + 1, -1));
        getLongestRepeatedSubarrayLength(nums1, nums2, dp);
        return ans;
    }
};
class Solution {
    
int dp[1000][1000];
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for (int i = 0; i < 1000; ++i)
            for(int j = 0; j < 1000; ++j)
                dp[i][j] = INT_MIN;
        
        return DP(nums, multipliers, 0, 0, nums.size() - 1);
    }
    
    int DP(vector<int>& nums, vector<int>& multi, int i, int l, int r) {
        if (i == multi.size()) 
            return 0;
        
        if (dp[l][i] != INT_MIN)
            return dp[l][i];
        
        int lft = multi[i] * nums[l] + DP(nums, multi, i + 1, l + 1, r);
        int rgt = multi[i] * nums[r] + DP(nums, multi, i + 1, l, r - 1);
        
        dp[l][i] = max(lft, rgt);
        
        return dp[l][i];
    }
};
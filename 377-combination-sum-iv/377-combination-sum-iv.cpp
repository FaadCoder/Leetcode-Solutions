class Solution {
    int dp[1002];
    int getWays(vector<int> &nums,int target)
    {
        if(target<0)
            return 0;
        
        if(target == 0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int res=0;
        for(int num:nums)
            res += getWays(nums,target-num);
        
        return dp[target] = res;
        
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return getWays(nums,target);
    }
};
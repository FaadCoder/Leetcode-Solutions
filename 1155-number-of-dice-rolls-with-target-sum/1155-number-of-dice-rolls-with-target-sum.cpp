class Solution {
    const int MOD = 1e9+7;
    unordered_map<int,unordered_map<int,int>> dp;
public:
    int numRollsToTarget(int n, int k, int target) {
        if(target<0 or n<0)
            return 0;
        
        if(target==0)
            return n==0;
        
        if(dp.count(n) and dp[n].count(target))
            return dp[n][target];
        
        int res = 0;
        
        for(int faceUp = 1; faceUp<=k; faceUp++)
        {
            res = (res + numRollsToTarget(n-1,k,target-faceUp))%MOD;
        }
        
        return dp[n][target] = res;
    }
};
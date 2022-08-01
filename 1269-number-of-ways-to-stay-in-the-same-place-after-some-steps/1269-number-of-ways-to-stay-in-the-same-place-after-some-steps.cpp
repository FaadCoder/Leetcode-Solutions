class Solution {
    const int MOD = 1e9+7;
    unordered_map<int,unordered_map<int,int>> dp;
    
    int addUnderModulo(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;   
    }
    
    int getTotalWays(int steps,int arrLen,int idx=0)
    {
        if(idx<0 or idx>=arrLen or steps<0)
            return 0;
        
        if(steps==0)
            return idx==0;
        
        if(dp.count(steps) and dp[steps].count(idx))
            return dp[steps][idx];
        
        return dp[steps][idx] = addUnderModulo(getTotalWays(steps-1,arrLen,idx),
                              addUnderModulo(getTotalWays(steps-1,arrLen,idx+1),getTotalWays(steps-1,arrLen,idx-1)));
            
    }
    
public:
    int numWays(int steps, int arrLen) {
        return getTotalWays(steps,arrLen);
    }
};
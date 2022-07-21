class Solution
{
    int dp[(1<<20) + 1];
    
    bool canFirstPlayerWin(int maxInteger, int total, int bitmask = 0)
    {
        if(total<=0)
            return  dp[bitmask] = false;
        
        if(dp[bitmask]!=-1)
            return dp[bitmask];
        
        for (int integer = maxInteger; integer >= 1; integer--)
        {
            if ((bitmask &(1 << (integer-1))) == 0)
            {
                if (integer >= total)
                    return dp[bitmask] = true;
                if (!canFirstPlayerWin(maxInteger, total - integer, bitmask | 1 << (integer-1)))
                    return dp[bitmask] = true;
            }
        }
        return dp[bitmask] = false;
    }

    public:
        bool canIWin(int maxChoosableInteger, int desiredTotal)
        {
            int sum = maxChoosableInteger *(maxChoosableInteger + 1) / 2;

            if (maxChoosableInteger > desiredTotal)
                return true;

            if (sum < desiredTotal)
                return false;

            if (sum == desiredTotal)
                return maxChoosableInteger % 2;
            memset(dp,-1,sizeof(dp));
            return canFirstPlayerWin(maxChoosableInteger, desiredTotal);
        }
};
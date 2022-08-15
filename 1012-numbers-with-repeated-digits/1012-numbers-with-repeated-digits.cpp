class Solution
{

    int dp[11][2][2][1024];

    int countNumbers(string &str, int pos = 0, int tight = 1, int repeated = 0, int mask = 0)
    {
        if (pos == str.length())
            return ((mask != 0) and (repeated != 0));
        
        
        if(dp[pos][tight][repeated][mask] != -1)
            return dp[pos][tight][repeated][mask];
        
        int count = 0;

        
        
        if (tight)
        {
            for (int digit = 0; digit <= str[pos] - '0'; digit++)
            {
                int newRepeated = repeated or (((mask == 0 and digit == 0) ? 0 : ((mask & (1 << digit)) != 0)));
                int newMask = ((mask == 0 and digit == 0) ? 0 : (mask | (1 << digit)));

                if (digit == str[pos] - '0')
                    count += countNumbers(str, pos + 1, 1, newRepeated, newMask);
                else
                    count += countNumbers(str, pos + 1, 0, newRepeated, newMask);
            }
        }
        else
        {
            for (int digit = 0; digit <= 9; digit++)
            {
                int newRepeated = repeated or (((mask == 0 and digit == 0) ? 0 : ((mask & (1 << digit)) != 0)));
                int newMask = ((mask == 0 and digit == 0) ? 0 : (mask | (1 << digit)));

                count += countNumbers(str, pos + 1, 0, newRepeated, newMask);
            }
        }

        return dp[pos][tight][repeated][mask] = count;
    }

    public:
        int numDupDigitsAtMostN(int n)
        {
            string str = to_string(n);
            memset(dp, -1, sizeof(dp));
            return countNumbers(str);
        }
};
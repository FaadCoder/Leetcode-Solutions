/*
Algorithm:
- start putting the numbers from last,
- APart from Greatest number no number will be visible if put at the last position
- dp(n,k) = dp(n-1,k-1) + (n-1) *dp(n-1,k)
              Greatest  + Other numbers

*/
class Solution
{
    const int MOD = 1e9 + 7;
    vector<vector < int>> dp;

    int add(int a, int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }

    int mul(long long a, long long b)
    {
        return (a % MOD *b % MOD) % MOD;
    }

    int sub(int a, int b)
    {
        return (a - b + MOD) % MOD;
    }

    int getTotalWays(int n, int k)
    {
        if (n == k)
            return 1;
        if (n == 0 or k == 0)
            return 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        return dp[n][k] = add(getTotalWays(n - 1, k - 1), mul(sub(n, 1), getTotalWays(n - 1, k)));
    }

    int getTotalWaysBottomUp(int n, int k)
    {
        vector<vector < int>> cache(n + 1, vector<int> (k + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == j)
                {
                    cache[i][j] = 1;
                }
                else
                {
                    cache[i][j] = add(cache[i - 1][j - 1], mul(sub(i, 1), cache[i - 1][j]));
                }
            }
        }
        return cache[n][k];
    }

    int getTotalWaysBottomUpSpaceOptimized(int n, int k)
    {
        vector<int> curr(k + 1, 0);
        vector<int> prev(k + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == j)
                {
                    curr[j] = 1;
                }
                else
                {
                    curr[j] = add(prev[j - 1], mul(sub(i, 1), prev[j]));
                }
            }
            prev = curr;
        }
        return curr[k];
    }

    public:
        int rearrangeSticks(int n, int k)
        {
            dp.resize(n + 1, vector<int> (k + 1, -1));

            return getTotalWaysBottomUpSpaceOptimized(n, k);
        }
};
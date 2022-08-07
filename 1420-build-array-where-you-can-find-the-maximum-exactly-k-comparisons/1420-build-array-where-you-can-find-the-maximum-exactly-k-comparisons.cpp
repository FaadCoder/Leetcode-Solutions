class Solution
{
    const int MOD = 1e9 + 7;
    vector<vector<vector< int>>> dp;

    int add(int a, int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }

    int getTotalWays(int n, int m, int k, int mx = 0)
    {
        if (n == 0)
        {
            return k == 0;
        }

        if (dp[n][mx][k] != -1)
            return dp[n][mx][k];

        int totalWays = 0;

        for (int num = 1; num <= m; num++)
        {
            if (num <= mx)
                totalWays = add(totalWays, getTotalWays(n - 1, m, k, mx));
            else if (mx < num and k - 1 >= 0)
                totalWays = add(totalWays, getTotalWays(n - 1, m, k - 1, num));
        }

        return dp[n][mx][k] = totalWays;
    }

    public:
        int numOfArrays(int n, int m, int k)
        {
            dp.resize(n + 1, vector<vector < int>> (m + 1, vector<int> (k + 1, -1)));
            return getTotalWays(n, m, k);
        }
};
class Solution
{
    vector<vector<int>> dp;
    
    const int MOD = 1e9 + 7;
    int add(int a, int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }

    int get(char curr)
    {
        if(curr == 'a')
            return 0;
        if(curr == 'e')
            return 1;
        if(curr == 'i')
            return 2;
        if(curr == 'o')
            return 3;
        if(curr == 'u')
            return 4;
        return -1;
    }
    
    int countPermutation(int n, char curr)
    {
        if (n == 0)
        {
            return 1;
        }

        if(dp[n][get(curr)]!=-1)
            return dp[n][get(curr)];
        
        int total = 0;
        if (curr == 'a')
            total = add(total, countPermutation(n - 1, 'e'));

        if (curr == 'e')
            total = add(total, add(countPermutation(n - 1, 'a'), countPermutation(n - 1, 'i')));

        if (curr == 'i')
            total = add(total, add(countPermutation(n - 1, 'a'),
                add(countPermutation(n - 1, 'e'),
                    add(countPermutation(n - 1, 'o'),
                        countPermutation(n - 1, 'u')))));

        if (curr == 'o')
            total = add(total, add(countPermutation(n - 1, 'i'), countPermutation(n - 1, 'u')));

        if (curr == 'u')
            total = add(total, countPermutation(n - 1, 'a'));

        return dp[n][get(curr)] = total;
    }

    public:
        int countVowelPermutation(int n)
        {
            dp.resize(n+1,vector<int>(5,-1));
            int total = 0;
            for (char ch:
                {
                    'a',
                    'e',
                    'i',
                    'o',
                    'u' })
            {
                total = add(total,countPermutation(n - 1, ch));
            }
            return total;
        }
};
class Solution
{

    int height, width;
    vector<int> bricks;
    vector<int> allMasks;
    const int MOD = 1e9 + 7;
    int dp[101][(1 << 10) + 1];
    int addUnderModulo(int a, int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }

    void getAllPossibleMasks(int currentWidth, int currentMask)
    {
        if (currentWidth > width)
            return;
        if (currentWidth == width)
            allMasks.push_back(currentMask);
        else
        {
            if (currentWidth)
            {
                currentMask |= 1 << (currentWidth - 1);
            }
            for (int brick: bricks)
            {
                int pos = currentWidth + brick;
                getAllPossibleMasks(currentWidth + brick, currentMask);
            }
        }
    }

    int getWays(int currentHeight = 0, int prev = 0)
    {
        if (currentHeight == height)
            return 1;
        if (dp[currentHeight][prev] != -1)
            return dp[currentHeight][prev];
        int ways = 0;
        for (int mask: allMasks)
        {
            if ((prev & mask) == 0)
                ways = addUnderModulo(ways, getWays(currentHeight + 1, mask));
        }
        return dp[currentHeight][prev] = ways;
    }

    public:
        int buildWall(int height, int width, vector<int> &bricks)
        {
            this->height = height;
            this->width = width;
            this->bricks = bricks;
            getAllPossibleMasks(0, 0);
            memset(dp, -1, sizeof(dp));
            return getWays();
        }
};
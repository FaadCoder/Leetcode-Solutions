class Solution
{
    const int mod = 1e9 + 7;

    long long int subtractUnderModulo(long long int a, long long int b)
    {
        int res = (a % mod - b % mod) % mod;
        if (res < 0)
            res += mod;
        return res;
    }

    long long int productUnderModulo(long long int a, long long int b)
    {
        return (a % mod *b % mod) % mod;
    }

    public:
        int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
        {
            horizontalCuts.push_back(0);
            horizontalCuts.push_back(h);
            verticalCuts.push_back(0);
            verticalCuts.push_back(w);

            sort(begin(horizontalCuts), end(horizontalCuts));
            sort(begin(verticalCuts), end(verticalCuts));

            long long int maxDiffBetweenHorizontalLines = 0;

            for (int horizontalLine = 1; horizontalLine < horizontalCuts.size(); horizontalLine++)
                maxDiffBetweenHorizontalLines = max(maxDiffBetweenHorizontalLines,
                    subtractUnderModulo(horizontalCuts[horizontalLine], horizontalCuts[horizontalLine - 1]));

            long long int maxDiffBetweenVerticalLines = 0;

            for (int verticalLine = 1; verticalLine < verticalCuts.size(); verticalLine++)
                maxDiffBetweenVerticalLines = max(maxDiffBetweenVerticalLines,
                    subtractUnderModulo(verticalCuts[verticalLine], verticalCuts[verticalLine - 1]));

            return productUnderModulo(maxDiffBetweenHorizontalLines, maxDiffBetweenVerticalLines);
        }
};
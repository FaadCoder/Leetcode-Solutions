class Solution
{
    int getDistance(int idx1, int idx2)
    {
        return abs(idx2 - idx1) + 1;
    }

    public:
        int minimumCardPickup(vector<int> &cards)
        {
            unordered_map<int, int> posMap;
            int minDist = INT_MAX;
            for (int idx = 0; idx < cards.size(); idx++)
            {
                if (posMap.count(cards[idx]))
                    minDist = min(minDist, getDistance(idx, posMap[cards[idx]]));
                posMap[cards[idx]] = idx;
            }

            return minDist == INT_MAX ? -1 : minDist;
        }
};
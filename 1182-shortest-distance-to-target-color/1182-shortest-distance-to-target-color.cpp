class Solution
{
    void populateShortestDistance(vector<int> &colors,
        int color,
        unordered_map<int, unordered_map<int, int>> &idxToColorShortestDistanceValue)
    {
        int numberOfElements = colors.size();
        vector<int> left(numberOfElements, -1), right(numberOfElements, -1);

        left[0] = (colors[0] == color) ? 0 : -1;

        for (int colorIdx = 1; colorIdx < size(colors); colorIdx++)
        {
            if (colors[colorIdx] == color)
                left[colorIdx] = 0;
            else
                left[colorIdx] = (left[colorIdx - 1] == -1) ? -1 : 1 + left[colorIdx - 1];
        }

        right[numberOfElements - 1] = (colors.back() == color) ? 0 : -1;

        for (int colorIdx = numberOfElements - 2; colorIdx >= 0; colorIdx--)
        {
            if (colors[colorIdx] == color)
                right[colorIdx] = 0;
            else
                right[colorIdx] = (right[colorIdx + 1] == -1) ? -1 : 1 + right[colorIdx + 1];
        }

        for (int idx = 0; idx < colors.size(); idx++)
        {
            if (left[idx] == -1 or right[idx] == -1)
                idxToColorShortestDistanceValue[idx][color] = max(left[idx], right[idx]);
            else
                idxToColorShortestDistanceValue[idx][color] = min(left[idx], right[idx]);
        }
    }
    public:
        vector<int> shortestDistanceColor(vector<int> &colors, vector<vector< int>> &queries)
        {
            int numberOfElements = colors.size();
            unordered_map<int, unordered_map<int, int>> idxToColorShortestDistanceValue;

            for (int color = 1; color <= 3; color++)
                populateShortestDistance(colors, color, idxToColorShortestDistanceValue);

            vector<int> ans;

            for (auto &query: queries)
            {
                int idx = query[0];
                int color = query[1];
                if (!idxToColorShortestDistanceValue.count(idx) or!idxToColorShortestDistanceValue[idx].count(color))
                    ans.push_back(-1);
                else
                {
                    int queryVal = idxToColorShortestDistanceValue[idx][color];
                    queryVal = (queryVal == INT_MIN) ? -1 : queryVal;
                    ans.push_back(queryVal);
                }
            }

            return ans;
        }
};

// idx-> 1,2,3 minDistance;
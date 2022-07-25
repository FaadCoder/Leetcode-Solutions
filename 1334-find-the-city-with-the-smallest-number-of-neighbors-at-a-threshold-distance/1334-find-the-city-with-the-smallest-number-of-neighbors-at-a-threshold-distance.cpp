class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int distanceThreshold)
        {
            vector<vector < int>> dis(n, vector<int> (n, INT_MAX));

            for (auto edge: edges)
            {
                int from = edge[0];
                int to = edge[1];
                int cost = edge[2];
                dis[from][to] = cost;
                dis[to][from] = cost;
            }

            for (int i = 0; i < n; i++)
                dis[i][i] = 0;

            for (int helperVertex = 0; helperVertex < n; helperVertex++)
            {
                for (int from = 0; from < n; from++)
                {
                    for (int to = 0; to < n; to++)
                    {
                        if (dis[from][helperVertex] != INT_MAX and dis[helperVertex][to] != INT_MAX)
                            dis[from][to] = min(dis[from][to], dis[from][helperVertex] + dis[helperVertex][to]);
                    }
                }
            }

            int smallest = INT_MAX;
            int idx = -1;
            for (int from = 0; from < n; from++)
            {
                int count = 0;
                for (int to = 0; to < n; to++)
                    count += (dis[from][to] <= distanceThreshold);

                if (smallest >= count)
                    smallest = count, idx = from;
            }

            return idx;
        }
};
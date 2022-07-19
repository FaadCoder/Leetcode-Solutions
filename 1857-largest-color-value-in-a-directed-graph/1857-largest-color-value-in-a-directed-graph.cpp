struct GraphNode
{
    GraphNode(): inDegree(0), neighbors(), count(vector<int> (26, 0)) {}
    int inDegree;
    vector<int> neighbors;
    vector<int> count;
};
class Solution
{
    public:
        int largestPathValue(string colors, vector<vector < int>> &edges)
        {
            int n = colors.size();
            vector<GraphNode> graph(n);
            for (auto &edge: edges)
            {
                int f = edge[0], t = edge[1];
                graph[f].neighbors.emplace_back(t);
                ++graph[t].inDegree;
            }
            queue<int> q;
            for (int i = 0; i < n; ++i)
            {
                if (graph[i].inDegree == 0)
                {
                    q.emplace(i);
                }
            }
            if (q.empty())
            {
                return -1;
            }
            int ans = 0;
            int popped = 0;
            while (!q.empty())
            {
                int id = q.front();
                q.pop();
                ++popped;
                ++graph[id].count[colors[id] - 'a'];
                for (int i = 0; i < 26; ++i)
                {
                    ans = max(ans, graph[id].count[i]);
                }
                for (int neighborId: graph[id].neighbors)
                {
                    for (int i = 0; i < 26; ++i)
                    {
                        graph[neighborId].count[i] = max(graph[neighborId].count[i], graph[id].count[i]);
                    }
                    if (--graph[neighborId].inDegree == 0)
                    {
                        q.emplace(neighborId);
                    }
                }
            }
            return popped == n ? ans : -1;
        }
};
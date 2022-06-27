class Solution
{
    vector<vector < int>> paths;

    void dfs(vector<vector < int>> &graph, vector< int > currentPath, int src = 0)
    {
        currentPath.push_back(src);
        if (src == graph.size() - 1)
        {
            paths.push_back(currentPath);
        }
        else
        {
            for (auto child: graph[src])
            {
                dfs(graph, currentPath, child);
            }
        }
        currentPath.pop_back();
    }

    public:
        vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
        {
            vector<int> currentPath;
            dfs(graph, currentPath);
            return paths;
        }
};
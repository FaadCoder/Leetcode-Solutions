class Solution
{

    unordered_map<int, int> rowMap, colMap;

    pair<bool, vector < int>> getTopo(vector<vector < int>> &conditions, 
                                      unordered_map< int, vector< int>> &graph, 
                                      int k)
    {
        vector<int> indegree(k + 1, 0);
        for (auto r: conditions)
        {
            indegree[r[1]]++;
            graph[r[0]].push_back(r[1]);
        }

        queue<int> q;

        for (int i = 1; i <= k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int top = q.front();
            topo.push_back(top);
            q.pop();

            for (auto it: graph[top])
            {
                indegree[it] -= 1;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return {
            topo.size() == k,
            topo
        };
    }

    public:
        vector<vector < int>> buildMatrix(int k, vector<vector < int>> &rowConditions, vector< vector< int>> &colConditions)
        {

            unordered_map<int, vector < int>> rowGraph, colGraph;

            auto rowTopo = getTopo(rowConditions, rowGraph, k);
            if (rowTopo.first == false)
                return {};

            auto colTopo = getTopo(colConditions, colGraph, k);

            if (!colTopo.first)
                return {};

            for (int idx = 0; idx < rowTopo.second.size(); idx++)
                rowMap[rowTopo.second[idx]] = idx;

            for (int idx = 0; idx < colTopo.second.size(); idx++)
                colMap[colTopo.second[idx]] = idx;

            vector<vector < int>> ans(k, vector<int> (k, 0));

            for (int i = 1; i <= k; i++)
                ans[rowMap[i]][colMap[i]] = i;

            return ans;
        }
};
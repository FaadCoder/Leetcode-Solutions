class Solution
{
    unordered_map<string, vector<pair<string, double>>> graph;

    double evaluateDivision(string &source, string &destination)
    {
        if (!graph.count(source) or!graph.count(destination))
            return -1.0;

        unordered_set<string> vis;
        queue<pair<string, double>> q;
        q.push({ source,
            1.0 });
        vis.insert(source);

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            string currentNode = front.first;
            double currentValue = front.second;
            if (currentNode == destination)
                return currentValue;

            for (auto child: graph[currentNode])
            {
                if (!vis.count(child.first))
                {
                    vis.insert(child.first);
                    q.push({ child.first,
                        currentValue *child.second });
                }
            }
        }
        return -1.0;
    }

    public:
        vector<double> calcEquation(vector<vector < string>> &equations, vector< double > &values, vector< vector< string>> &queries)
        {
            graph.clear();

            for (int idx = 0; idx < equations.size(); idx++)
            {
                graph[equations[idx][0]].push_back({ equations[idx][1],
                    values[idx] });
                graph[equations[idx][1]].push_back({ equations[idx][0],
                    1.0 / values[idx] });
            }

            vector<double> ans;

            for (auto query: queries)
            {
                ans.push_back(evaluateDivision(query[0], query[1]));
            }

            return ans;
        }
};
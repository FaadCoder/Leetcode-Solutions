class Solution
{

    void applyFloydWardshall(vector<vector < bool>> &isReachable, vector< vector< int>> &prerequisites)
    {
        int numCourses = isReachable.size();
        for (int vertex = 0; vertex < numCourses; vertex++)
            isReachable[vertex][vertex] = true;

        for (auto prerequisite: prerequisites)
        {
            int from = prerequisite[0];
            int to = prerequisite[1];
            isReachable[from][to] = true;
        }

        for (int helperVertex = 0; helperVertex < numCourses; helperVertex++)
        {
            for (int from = 0; from < numCourses; from++)
            {
                for (int to = 0; to < numCourses; to++)
                {
                    isReachable[from][to] = isReachable[from][to] or(isReachable[from][helperVertex] and isReachable[helperVertex][to]);
                }
            }
        }
    }

    vector<bool> getQueriesResult(vector<vector < bool>> &isReachable, vector< vector< int>> &queries)
    {
        vector<bool> queriesResult;

        for (auto query: queries)
            queriesResult.push_back(isReachable[query[0]][query[1]]);

        return queriesResult;
    }

    public:
        vector<bool> checkIfPrerequisite(int numCourses, vector<vector < int>> &prerequisites, vector< vector< int>> &queries)
        {
            vector<vector < bool>> isReachable(numCourses, vector<bool> (numCourses, false));

            applyFloydWardshall(isReachable, prerequisites);
            return getQueriesResult(isReachable, queries);
        }
};
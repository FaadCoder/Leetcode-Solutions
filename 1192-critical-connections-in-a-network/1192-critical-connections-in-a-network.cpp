class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        int ranks[n];
        fill_n(ranks, n, NO_RANK);
        vector<vector<int>> result;
        // Because whole graph is connected, there is no need to loop through every node.
        criticalConnections(graph, n, 0, 0, ranks, result);        
        
        return result;
    }
private:
    static const int NO_RANK;

    int criticalConnections(vector<int> graph[], int n, int node, int myRank, int ranks[], vector<vector<int>>& result) {
        if (ranks[node] != NO_RANK) {
            return ranks[node];
        }

        int lowestRank = myRank;
        ranks[node] = myRank;
        for (auto neighbor : graph[node]) {
            if (ranks[neighbor] == myRank - 1 || ranks[neighbor] == n) {
                // ranks[neighbor] == myRank - 1:
                // Do not go back immediately to parent, this will lead to
                // parent-child-parent circle immediately.
                // This is why NO_RANK is set to -2 instead of -1, because the first node of a recursion has myRank 0.
                //
                // ranks[neighbor] == n:
                // Do not include node=>neighbor in the result. Reason:
                // This can be explained from a couple of aspects:
                // - This means neighbor has been finished, so neighbor=>node has been decided before neighbor is finished,
                //   and if neighbor=>node is already decided, we don't need to make a decision on node=>neighbor because
                //   it is undirected graph.
                // - When neighbor=>node was decided, the decision must be "not include it in the result", because
                //   node is an ancestor of neighbor, so neighbor=>node is a back edge, meaning at that time it already
                //   detected that there is a cycle between neighbor and node, so that edge would not be included in the result.
                continue;
            }
            
            int neighborRank = criticalConnections(graph, n, neighbor, myRank + 1, ranks, result);
            lowestRank = min(lowestRank, neighborRank);
            if (neighborRank > myRank) {
                result.push_back({min(node, neighbor), max(node, neighbor)});
            }
            
        }
        
        ranks[node] = n;
        return lowestRank;
    }
};

const int Solution::NO_RANK = -2;
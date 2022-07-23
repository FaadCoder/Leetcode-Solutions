struct Pair
{
    int node;
    int cost;
    Pair(int _node, int _cost): node(_node), cost(_cost) {}
};

struct Compare
{
    bool operator()(Pair &pair1, Pair &pair2)
    {
        return pair1.cost > pair2.cost;
    };
};

class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &times, int n, int k)
        {

            vector<pair<int, int>> graph[n];
            for (auto &time: times)
                graph[time[0]-1].push_back({ time[1]-1,
                    time[2] });

            vector<int> dist(n, INT_MAX);
            dist[k-1] = 0;
            priority_queue<Pair, vector < Pair>, Compare> minHeap;
            minHeap.push(Pair(k-1, 0));
            while (!minHeap.empty())
            {
                auto top = minHeap.top();
                minHeap.pop();
                int node = top.node;
                int cost = top.cost;
                if (dist[node] > cost)
                    continue;
                for (auto child: graph[node])
                {
                    int newDist = cost + child.second;
                    if (dist[child.first] > newDist)
                    {
                        minHeap.push(Pair(child.first, newDist));
                        dist[child.first] = newDist;
                    }
                }
            }

            int maxTime = INT_MIN;
            for (int dis: dist)
            {
                // cout<<dis<<" ";
                if (dis == INT_MAX)
                    return -1;
                maxTime = max(maxTime, dis);
            }
            return maxTime;
        }
};
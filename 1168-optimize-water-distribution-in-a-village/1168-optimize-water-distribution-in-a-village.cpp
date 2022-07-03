class UnionFind
{
    private:
        unordered_map<int, int> parent, size;
    int numberOfSets;
    public:
        UnionFind(int numberOfElements)
        {
            numberOfSets = numberOfElements;
            parent.clear();
            size.clear();
            for (int element = 0; element <= numberOfElements; element++)
            {
                parent[element] = element;
                size[element] = 1;
            }
        }

    int findParent(int child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    bool unionSet(int set1, int set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);
        if (set1 == set2)
            return false;
        if (size[set1] < size[set2])
            swap(set1, set2);

        parent[set2] = set1;
        size[set1] += size[set2];

        return true;
    }
};

struct Edge
{
    int from;
    int to;
    int cost;
    Edge(int _from, int _to, int _cost)
    {
        from = _from;
        to = _to;
        cost = _cost;
    }
};

class Solution
{
    public:
        int minCostToSupplyWater(int n, vector<int> &wells, vector<vector< int>> &pipes)
        {
            vector<Edge> edges;
            for (auto &pipe: pipes)
                edges.push_back(Edge(pipe[0], pipe[1], pipe[2]));

            for (int well = 0; well < wells.size(); well++)
                edges.push_back(Edge(0, well + 1, wells[well]));

            sort(edges.begin(), edges.end(), [& ](Edge &edge1, Edge &edge2)
            {
                return edge1.cost < edge2.cost;
	        });

            UnionFind dsu(n);
            int minCost = 0;

            for (Edge &edge: edges)
            {
                if (dsu.unionSet(edge.from, edge.to))
                    minCost += edge.cost;
            }

            return minCost;
        }
};
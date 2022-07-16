class UnionFind
{
    unordered_map<int, int> parent, size;
    public:
        UnionFind(int n)
        {
            for (int i = 0; i <= n; i++)
                parent[i] = i, size[i] = 1;
        }

    int findParent(int child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int set1, int set2)
    {
        return findParent(set1) == findParent(set2);
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
class Solution
{
    public:
        vector<bool> areConnected(int n, int threshold, vector<vector < int>> &queries)
        {
            UnionFind unionFind(n);

            for (int city1 = threshold+1; city1 <= n; city1++)
            {
                for (int city2 = 2 * city1; city2 <= n; city2 += city1)
                {
                    
                        unionFind.unionSet(city2, city1);
                }
            }

            vector<bool> queryAns;
            for (auto &query: queries)
            {
                queryAns.push_back(unionFind.isConnected(query[0], query[1]));
            }
            return queryAns;
        }
};
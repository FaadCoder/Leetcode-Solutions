class UnionFind
{
    private:
        unordered_map<int, int> parent, size;
    int connectedComponents;
    public:

        UnionFind(int numberOfElements)
        {
            parent.clear();
            size.clear();
            for (int element = 0; element <= numberOfElements; element++)
            {
                parent[element] = element;
                size[element] = 1;
            }
            connectedComponents = numberOfElements;
        }

    int findParent(int child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    bool unionSet(int element1, int element2)
    {
        if (isConnected(element1, element2))
            return false;

        int parentOfElement1 = findParent(element1);
        int parentOfElement2 = findParent(element2);

        if (size[parentOfElement1] < size[parentOfElement2])
            swap(parentOfElement1, parentOfElement2);

        parent[parentOfElement2] = parentOfElement1;
        size[parentOfElement1] += size[parentOfElement2];
        connectedComponents -= 1;
        return true;
    }

    bool isConnected(int element1, int element2)
    {
        return (findParent(element1) == findParent(element2));
    }

    int getNumberOfSets()
    {
        return connectedComponents;
    }
};

class Solution
{
    public:
        int earliestAcq(vector<vector < int>> &logs, int n)
        {
            UnionFind dsu(n);
            sort(begin(logs),end(logs));
            
            for (auto &log: logs)
            {
                dsu.unionSet(log[1], log[2]);
                if (dsu.getNumberOfSets() == 1)
                    return log[0];
            }
            return -1;
        }
};
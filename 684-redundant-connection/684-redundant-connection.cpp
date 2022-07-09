class UnionFind
{
private:

    unordered_map<int, int> parent, size;
    int connectedComponents;
public:

    UnionFind(int sets)
    {
        connectedComponents = sets;
        parent.clear();
        size.clear();
        for (int set = 0; set<= sets; set++)
        {
            parent[set] = set;
            size[set] = 1;
        }
    }

    int findParent(int element)
    {
        if (element == parent[element])
            return element;
        return parent[element] = findParent(parent[element]);
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
        connectedComponents -= 1;
        return true;
    }

    int numberOfConnectedComponents()
    {
        return connectedComponents;
    }
};
class Solution
{
    public:
        vector<int> findRedundantConnection(vector<vector < int>> &edges) {
            vector<int> edgeToRemove;
            UnionFind unionFind(edges.size());
            
            for(auto &edge:edges)
            {
                if(!unionFind.unionSet(edge[0],edge[1]))
                    edgeToRemove = edge;
            }
            
            return edgeToRemove;
        }
};
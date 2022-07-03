class UnionFind{
private:
    unordered_map<int,int> parent,size;
    int connectedComponents;
public:
    
    UnionFind(int numberOfElements)
    {
        parent.clear();
        size.clear();
        for(int element = 0; element<=numberOfElements; element++)
        {
            parent[element] = element;
            size[element] = 1;
        }
        connectedComponents = numberOfElements;
    }
    
    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    bool unionSet(int element1,int element2)
    {
        if(isConnected(element1,element2))
            return false;
        
        int parentOfElement1 = findParent(element1);
        int parentOfElement2 = findParent(element2);
        
        if(size[parentOfElement1] < size[parentOfElement2])
            swap(parentOfElement1,parentOfElement2);
        
        parent[parentOfElement2] = parentOfElement1;
        size[parentOfElement1] += size[parentOfElement2];
        connectedComponents -= 1;
        return true;
    }
    
    bool isConnected(int element1,int element2)
    {
        return (findParent(element1)==findParent(element2));
    }
    
    int getNumberOfSets()
    {
        return connectedComponents;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        
        for(auto &edge:edges)
        {
            if(dsu.isConnected(edge[0],edge[1]))
                return false;
            dsu.unionSet(edge[0],edge[1]);
        }
        return (dsu.getNumberOfSets() == 1);
    }
};
class UnionFind{
 private:
    unordered_map<int,int> parent,size;
    int connectedComponents;
public:
    UnionFind(int n)
    {
        parent.clear();
        size.clear();
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        connectedComponents = n;
    }
    
    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    bool unionSets(int set1,int set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);
        
        if(set1==set2)
            return false;
        
        if(size[set1]<size[set2])
            swap(set1,set2);
        
        parent[set2] = set1;
        size[set1]+=size[set2];
        connectedComponents-=1;
        return true;
    }
    
    int getConnectedComponents()
    {
        return connectedComponents;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        int maxEdgesToRemove = 0;
        unordered_map<int,vector<pair<int,int>>> typeToEdgeHashMap;
        for(auto &edge:edges)
        {
            typeToEdgeHashMap[edge[0]].push_back({edge[1],edge[2]});
        }
        
        UnionFind unionFindBoth(n),unionFindAlice(n),unionFindBob(n);
        
        for(pair<int,int> &edge:typeToEdgeHashMap[3])
        {
            int from = edge.first;
            int to = edge.second;
            if(!unionFindBoth.unionSets(edge.first,edge.second))
            {
                maxEdgesToRemove++;
            }
            else
            {
                unionFindAlice.unionSets(edge.first,edge.second);
                unionFindBob.unionSets(edge.first,edge.second);
            }
        }
        
        for(pair<int,int> &edge:typeToEdgeHashMap[1])
        {
            int from = edge.first;
            int to = edge.second;
            if(!unionFindAlice.unionSets(edge.first,edge.second))
            {
                maxEdgesToRemove++;
            }
        }
        
        for(pair<int,int> &edge:typeToEdgeHashMap[2])
        {
            int from = edge.first;
            int to = edge.second;
            if(!unionFindBob.unionSets(edge.first,edge.second))
            {
                maxEdgesToRemove++;
            }
        }
        
        if(unionFindAlice.getConnectedComponents() == 1 and unionFindBob.getConnectedComponents()==1)
            return maxEdgesToRemove;
        return -1;
    }
};
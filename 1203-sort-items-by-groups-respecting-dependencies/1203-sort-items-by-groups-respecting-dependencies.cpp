/*
- Requires 2 level of Topological Sorting
- 1st Toposort will be for group order
- 2nd toposort will be for item order
*/

class Solution {
    
    vector<int> getTopoSort(unordered_map<int,vector<int>> &graph,vector<int> &indegree)
    {
        int coveredVertices = 0;
        int n = indegree.size();
        queue<int> bfsQueue;
        for(int vertex=0;vertex<n;vertex++)
        {
            if(indegree[vertex]==0)
                bfsQueue.push(vertex);
        }
        vector<int> topoSort;
        
        while(!bfsQueue.empty())
        {
            int top = bfsQueue.front();
            bfsQueue.pop();
            topoSort.push_back(top);
           
            coveredVertices++;
            for(auto child:graph[top])
            {
                indegree[child]-=1;
                if(indegree[child]==0)
                    bfsQueue.push(child);
            }
        }
        return (coveredVertices==n)?topoSort:vector<int>();
    }
    
    vector<int> buildGroupGraphAndGetIndegree(unordered_map<int,vector<int>> &groupGraph,
                                              vector<int>& group,
                                              vector<vector<int>>& beforeItems)
    {
        vector<int> indegree(group.size()+1,0);
        
        for(int idx=0;idx<group.size(); idx++)
        {
            int currentGroup = group[idx];
            for(int item:beforeItems[idx])
            {
                int previousGroup = group[item];
                if(currentGroup!=previousGroup)
                {
                    groupGraph[previousGroup].push_back(currentGroup);
                    indegree[currentGroup]++;   
                }
            }
        }
        return indegree;
    }
    
     vector<int> buildItemsGraphAndGetIndegree(unordered_map<int,vector<int>> &itemsGraph,
                                              vector<vector<int>>& beforeItems)
    {
        vector<int> indegree(beforeItems.size(),0);
        
        for(int idx=0;idx<beforeItems.size(); idx++)
        {
            for(int item:beforeItems[idx])
            {
                itemsGraph[item].push_back(idx);
                indegree[idx]++;   
            }
        }
        return indegree;
    }
    
    
    public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int idx=0;idx<group.size();idx++)
        {
            if(group[idx]==-1)
                group[idx] = m++;
        }
        unordered_map<int,vector<int>> groupGraph,itemsGraph;
        
        vector<int> groupIndegree = buildGroupGraphAndGetIndegree(groupGraph,group,beforeItems);
        
        vector<int> itemsIndegree = buildItemsGraphAndGetIndegree(itemsGraph,beforeItems);
        
        vector<int> groupsTopoSort = getTopoSort(groupGraph,groupIndegree);
        vector<int> itemsTopoSort = getTopoSort(itemsGraph,itemsIndegree);
        
        if(groupsTopoSort.empty() or itemsTopoSort.empty())
            return vector<int>();
        
        unordered_map<int,vector<int>> groupToItemHashMap;
        
        for(int item:itemsTopoSort)
            groupToItemHashMap[group[item]].push_back(item);
        
        vector<int> sortedItems;
        
        for(int group:groupsTopoSort)
        {
            for(int item:groupToItemHashMap[group])
                sortedItems.push_back(item);
        }
        return sortedItems;
     
    }
};
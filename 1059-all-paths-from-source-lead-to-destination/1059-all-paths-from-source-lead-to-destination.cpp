class Solution {
    unordered_map<int,vector<int>> graph;
    bool checkCycle(int src,vector<int> &dfsVis,vector<int> &vis)
    {
        dfsVis[src] = 1;
        vis[src] = 1;
        
        for(auto child:graph[src])
        {
           if(!vis[child] and checkCycle(child,dfsVis,vis))
               return true;
            else if(dfsVis[child])
            {
                return true;
            }
            
        }
        
        dfsVis[src] = 0;
        return false;
    }
    
    public:
       bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
            for(auto edge:edges)
            {
                graph[edge[0]].push_back(edge[1]);
            }
           
          
           
           vector<int> dfsVis(n,0),vis(n,0);
           bool didCycleExist = checkCycle(source,dfsVis,vis);
           if(didCycleExist)
               return false;
           for(int i=0;i<n;i++)
           {
               if(vis[i] and graph[i].empty() and i!=destination)
               {
                   return false;
               }
           }
           return true;
    }
};
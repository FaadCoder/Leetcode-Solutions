class Solution {
    unordered_map<int,vector<int>> graph;
    double getProb(int src,int target,int t,vector<bool> &vis)
    {
        if(src!=1 and graph[src].size()==1 or t==0)
            return src==target;
        vis[src] = true;
        double prob = 0;
        for(auto child:graph[src])
        {
            if(!vis[child])
            {
                int countNodes = graph[src].size()-(src!=1);
                prob += (1.0/countNodes) * getProb(child,target,t-1,vis);
                
            }
        }
        return prob;
    }
    
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) return 1.0;
        
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n+1,false);
        return getProb(1,target,t,vis);
    }
};
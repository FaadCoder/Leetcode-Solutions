class Solution {
    const int MOD = 1e9+7;
    int numberOfVertex;
    unordered_map<int,vector<pair<int,int>>> graph;
    int dp[20001];
    int addUnderModulo(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;
    }
    
    void buildGraph(vector<vector<int>>& edges)
    {
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
    }
    
    void populateShortestDistances(vector<int> &dis,int src)
    {
        dis[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        minHeap.push({0,src});
        while(!minHeap.empty())
        {
            auto [cost,from] = minHeap.top();
            minHeap.pop();
            
            if(dis[from] < cost)
                continue;
            
            for(auto &child:graph[from])
            {
                int newCost = cost + child.second;
                int to = child.first;
                if(dis[to] > newCost)
                {
                    dis[to] = newCost;
                    minHeap.push({newCost,to});
                }
            }
        }
    }
    
    int getTotalRestrictedPaths(vector<int> &dis,int src=1)
    {
        if(src==dis.size()-1)
            return 1;
        
        if(dp[src]!=-1)
            return dp[src];
        
        int paths = 0;
        
        for(auto child:graph[src])
        {
            if(dis[src]>dis[child.first])
                paths = addUnderModulo(paths,getTotalRestrictedPaths(dis,child.first));
        }
        
        return dp[src] = paths;
    }
    
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        numberOfVertex = n;
        buildGraph(edges);
        
        vector<int> dis(n+1,INT_MAX);
        dis[n] = 0;
        populateShortestDistances(dis,n);
        
        memset(dp,-1,sizeof(dp));
        return getTotalRestrictedPaths(dis);
    }
};
class Solution {
    vector<vector<int>> paths;
    
    void dfs(vector<vector<int>>& graph,vector<int> currentPath,vector<bool> &vis,int src = 0)
    {
        if(src == graph.size()-1)
        {
            paths.push_back(currentPath);
            currentPath.clear();
            currentPath.push_back(0);
            return;
        }
        vis[src] = true;
        for(auto child:graph[src])
        {
            if(!vis[child])
            {
                currentPath.push_back(child);
                dfs(graph,currentPath,vis,child);
                currentPath.pop_back();
            }
        }
        vis[src] = false;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int> currentPath;
        currentPath.push_back(0);
        vector<bool> vis(graph.size(),false);
        dfs(graph,currentPath,vis);
        return paths;
    }
};
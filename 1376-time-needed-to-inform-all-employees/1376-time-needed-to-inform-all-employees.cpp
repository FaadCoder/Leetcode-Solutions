class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        int headId = 0;
        for(int employeeId = 0; employeeId<manager.size(); employeeId++)
        {
            if(manager[employeeId]==-1)
                headId = employeeId;
            else
                adj[manager[employeeId]].push_back(employeeId);
        }
        
        int maxTimeToReachLeaf = 0;
        
        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({headId,0});
        while(!bfsQueue.empty())
        {
            pair<int,int> top = bfsQueue.front();
            bfsQueue.pop();
            int currentManagerId = top.first;
            int timePassed = top.second;
            maxTimeToReachLeaf = max(maxTimeToReachLeaf,timePassed);
            
            for(int employeeId:adj[currentManagerId])
            {
                bfsQueue.push({employeeId,timePassed + informTime[currentManagerId]});
            }
        }
        
        return maxTimeToReachLeaf;
    }
};
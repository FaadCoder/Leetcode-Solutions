class Solution {
    int dp[1002][1002];
    unordered_map<int,vector<pair<int,int>>> graph;
    vector<int> fees;
    
    int getMinCost(int src,int maxTime)
    {
        if(src==fees.size()-1)
            return 0;
        if(dp[src][maxTime]!=-1)
            return dp[src][maxTime];
       
        int res = INT_MAX/2;
        for(auto child:graph[src])
        {
            if(maxTime>=child.second)
            res = min(res,fees[src] + getMinCost(child.first,maxTime-child.second));    
        }
        
        return dp[src][maxTime] = res;
    }
    
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        fees = passingFees;
        memset(dp,-1,sizeof(dp));
        int ans = fees[fees.size()-1]+getMinCost(0,maxTime);
        return ans>=INT_MAX/2 ? -1 : ans;
    }
};
class Solution {
    int dp[11][(1<<11)];
    int getDistance(int x1, int x2, int y1, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int getMinCost(vector<vector<int>>& workers, vector<vector<int>>& bikes, int idx = 0, int mask = 0)
    {
        if(idx>=workers.size())
            return 0;
        
        if(dp[idx][mask]!=-1)
            return dp[idx][mask];
        
        int res = INT_MAX/2;
        
        for(int bike = 0; bike < bikes.size(); bike++)
        {
            if(mask & (1<<bike))
                continue;
            
            int x1 = workers[idx][0];
            int y1 = workers[idx][1];
            int x2 = bikes[bike][0];
            int y2 = bikes[bike][1];
            
            res = min(res, getDistance(x1, x2, y1, y2) + getMinCost(workers, bikes, idx + 1, mask | (1<<bike)));
        }
        
        return dp[idx][mask] = res;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memset(dp, -1, sizeof(dp));
        return getMinCost(workers, bikes);
    }
};
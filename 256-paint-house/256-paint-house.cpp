class Solution {
    
    int dp[102][4];
    
    int getMinCostToPaintHouse(vector<vector<int>>& costs,int houseIdx = 0,int prevColor = -1)
    {
        if(houseIdx >= costs.size())
            return 0;
        
        if(dp[houseIdx][prevColor+1]!=-1)
            return dp[houseIdx][prevColor+1];
        
        int minCost = INT_MAX;
        
        for(int color = 0; color < 3; color++)
        {
            if(prevColor == color)
                continue;
            minCost = min(minCost,costs[houseIdx][color] + getMinCostToPaintHouse(costs,houseIdx+1,color));
        }
        
        return dp[houseIdx][prevColor+1] = minCost;
    }
    
public:
    int minCost(vector<vector<int>>& costs) 
    {
        memset(dp,-1,sizeof(dp));
        return getMinCostToPaintHouse(costs);
    }
};
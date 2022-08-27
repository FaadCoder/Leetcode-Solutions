class Solution {
    
    int dp[366];
    
    int getMinCost(vector<int> &days, vector<int> &costs, int idx = 0)
    {
        if(idx >= days.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];
        
        int minCost = INT_MAX/2;
        
        for(int dayPass = 0; dayPass < costs.size(); dayPass++)
        {
            int daysCoveredByPass = (dayPass==0) ? 1 : (dayPass==1 ? 7 : 30);
            int newDay = daysCoveredByPass + days[idx] - 1;
            int newIdx = (upper_bound(begin(days), end(days), newDay) - begin(days));
            minCost = min(minCost, costs[dayPass] + getMinCost(days, costs, newIdx));
        }
        
        return dp[idx] = minCost;
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return getMinCost(days, costs);
    }
};
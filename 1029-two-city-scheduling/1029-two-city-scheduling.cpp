class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        vector<pair<int,int>> savings;
        for(int idx=0; idx<costs.size(); idx++)
            savings.push_back({costs[idx][0]-costs[idx][1],idx});
        int sumA = 0;
        int sumB = 0;
        sort(savings.begin(),savings.end());
        int n = costs.size();
        for(int i=0;i<n/2;i++)
            sumA += costs[savings[i].second][0];
        
        for(int i=n/2;i<n;i++)
            sumB += costs[savings[i].second][1];
              
        return sumA + sumB;
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        sort(costs.begin(),costs.end(),[&](vector<int> &a,vector<int> &b){
            return (a[1]-a[0] > b[1] - b[0]);
        });
        int cost = 0;
        int n = costs.size();
        for(int idx=0; idx<n; idx++)
            cost += (idx>=(n/2))?costs[idx][1]:costs[idx][0];
        return cost;
    }
};
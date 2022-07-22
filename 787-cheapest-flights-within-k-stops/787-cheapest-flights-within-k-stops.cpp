class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src==dst)
            return 0;
        vector<int> current(n,INT_MAX/2),prev(n,INT_MAX/2);
        current[src] = prev[src] = 0;
        for(int itr=1;itr<=k+1;itr++)
        {
            
            for(auto &flight:flights)
            {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                current[to] = min(current[to],prev[from]+cost);
            }
            prev = current;
        }
        return prev[dst]>=INT_MAX/2 ? -1 : prev[dst];
    }
};
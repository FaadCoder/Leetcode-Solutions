class Solution {
    const int MOD = 1e9+7;
    
    unordered_map<int,unordered_map<int,int>> dp;
    
    int addUnderMod(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;
    }
    
    int countRoutesHelper(vector<int>& locations, int start, int finish, int fuel) {
        
        if(dp.count(start) and dp[start].count(fuel))
            return dp[start][fuel];
        if(start==finish)
        {
            if(fuel==0)
            return 1;
            else
            {
                int totalRoutes = 1;
                for(int city = 0; city<locations.size(); city++)
                {
                    if(city!=start and fuel>=abs(locations[start]-locations[city]))
                        totalRoutes = addUnderMod(totalRoutes, 
                                                  countRoutesHelper(locations,city,finish,fuel-abs(locations[start]-locations[city])));
                }
                return dp[start][fuel] = totalRoutes;
            }
        }
        
        if(start>=locations.size())
            return 0;
        
        int totalRoutes = 0;
        for(int city = 0; city<locations.size(); city++)
        {
            if(city!=start and fuel>=abs(locations[start]-locations[city]))
                totalRoutes = addUnderMod(totalRoutes, 
                                          countRoutesHelper(locations,city,finish,fuel-abs(locations[start]-locations[city])));
        }
        return dp[start][fuel] = totalRoutes;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        return countRoutesHelper(locations,start,finish,fuel);
    }
};
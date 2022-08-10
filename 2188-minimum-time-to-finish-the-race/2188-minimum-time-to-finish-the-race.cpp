class Solution {
    vector<long long> dp,best;
    long long maxLaps = INT_MIN;
    
    long long getMinTime(long long numLaps, long long changeTime)
    {
        if(numLaps == 0)
            return -changeTime;
        
        if(dp[numLaps] != -1)
            return dp[numLaps];
        
        dp[numLaps] = INT_MAX;
        
        for(long long lap = 1; lap<=min(numLaps, maxLaps); lap++)
            dp[numLaps] = min(dp[numLaps], best[lap] + changeTime + getMinTime(numLaps - lap, changeTime));
        
        return dp[numLaps];
    }
    
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        best.resize(numLaps+1, INT_MAX);
        
        // 1. Calulate min time to complete a lap using single tire without changing tire.
        for(auto tire:tires)
        {
            long long f = tire[0];
            long long r = tire[1];
            long long totalTime = f;
            long long lapTime = f;
            for(long long lap=1; lap<=numLaps and (lapTime < changeTime + f); lap++)
            {
                maxLaps = max(maxLaps, lap);
                best[lap] = min(best[lap], totalTime);
                lapTime *= r; 
                totalTime += lapTime;
            }
        }
        
        dp.resize(numLaps+1,-1);
        
        // 2. Get minimum time using Top Down DP;
        return getMinTime(numLaps, changeTime);
    }
};
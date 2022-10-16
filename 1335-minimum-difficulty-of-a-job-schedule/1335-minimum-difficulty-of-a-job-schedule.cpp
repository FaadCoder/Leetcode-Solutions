class Solution {
    const int INF = INT_MAX/2;
    int dp[11][302];
    int getMinDifficulty(vector<int> &jobDifficulty, int d, int idx = 0)
    {
        if(d == 0 and idx >= size(jobDifficulty))
            return 0;
        
        if(d==0 or idx>=size(jobDifficulty))
            return INF;
        
        if(dp[d][idx] != -1)
            return dp[d][idx];
        
        int currMax = jobDifficulty[idx];
        int minDifficulty = INT_MAX;
        
        for(int job = idx; job < size(jobDifficulty); job++)
        {
            currMax = max(currMax, jobDifficulty[job]);
            minDifficulty = min(minDifficulty, currMax + getMinDifficulty(jobDifficulty, d - 1, job + 1));
        }
        
        return dp[d][idx] = minDifficulty;
        
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(d > size(jobDifficulty))
            return -1;
        
        if(d == size(jobDifficulty))
            return accumulate(begin(jobDifficulty), end(jobDifficulty), 0);
        
        memset(dp, -1, sizeof(dp));
        
        return getMinDifficulty(jobDifficulty, d);
    }
};
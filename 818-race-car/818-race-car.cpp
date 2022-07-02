class Solution {
    int dp[10002];
public:
    int racecar(int target) 
    {
        if(dp[target] > 0)
            return dp[target];
        
        int steps = ceil(log2(target+1));
        if(target+1 == (1<<steps))
            dp[target] = steps;
        else
        {
            dp[target] = steps + 1 + racecar((1<<steps) - 1 - target);
            for(int backwardSteps = 0;backwardSteps < steps - 1;backwardSteps++)
            {
                
                dp[target] = min(dp[target],
                                 steps+backwardSteps+1+racecar(target-(1<<steps-1)+(1<<backwardSteps)));
            }
            
        }
        return dp[target];
    }
};
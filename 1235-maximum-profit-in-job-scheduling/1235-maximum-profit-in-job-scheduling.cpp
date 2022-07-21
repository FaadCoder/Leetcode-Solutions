class Solution {
    int dp[50001];
    int getMaxProfit(vector<vector<int>> &events,vector<int> &startTime, int idx=0)
    {
        if(idx>=events.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int nextIdx = lower_bound(begin(startTime)+idx,end(startTime),events[idx][1]) - startTime.begin();
        
        return dp[idx] = max(getMaxProfit(events,startTime,idx+1),events[idx][2]+getMaxProfit(events,startTime,nextIdx));
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> events;
        memset(dp,-1,sizeof(dp));
        
        for(int idx=0;idx<startTime.size(); idx++)
            events.push_back({startTime[idx],endTime[idx],profit[idx]});    
        
        sort(events.begin(),events.end());
        sort(startTime.begin(),startTime.end());
        return getMaxProfit(events,startTime);
    }
};
class Solution {
    
    int getMaxValue(vector<vector<int>>& events, int k,vector<vector<int>> &dp,int idx=0)
    {
        if(k==0)
            return 0;
        if(idx>=events.size())
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        vector<int> temp = {events[idx][1],INT_MAX,INT_MAX};
        
        int nextIdx = upper_bound(events.begin()+idx,events.end(),temp)-events.begin();
        return dp[idx][k] = max(getMaxValue(events,k,dp,idx+1), events[idx][2]+getMaxValue(events,k-1,dp,nextIdx));
        
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return getMaxValue(events,k,dp);
    }
};
class Solution {
    int dp[100002][2][3];
    int getMaxProfit(vector<int>& prices,int idx=0,int currentAsk = 0,int transactions=0)
    {
        if(transactions>2)
            return INT_MIN/2;
        
        if(dp[idx][currentAsk][transactions]!=-1)
            return dp[idx][currentAsk][transactions];
        
        if(idx>=prices.size())
            return 0;
        
        if(currentAsk == 0)
        {
            return dp[idx][currentAsk][transactions] = max(getMaxProfit(prices,idx+1,0,transactions),getMaxProfit(prices,idx+1,1,transactions)-prices[idx]);
        }
    
        return dp[idx][currentAsk][transactions] = max(getMaxProfit(prices,idx+1,1,transactions),getMaxProfit(prices,idx+1,0,transactions+1)+prices[idx]);
    }
    
public:
    int maxProfit(vector<int>& prices)
    {
        memset(dp,-1,sizeof(dp));
        return getMaxProfit(prices);
    }
};
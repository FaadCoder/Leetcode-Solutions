class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int elements = nums.size();
        vector<int> dp(elements,1),count(elements,1);
        
        for(int curr = 1; curr<elements; curr++)
        {
            int currElement = nums[curr];
            
            for(int prev = 0; prev<curr; prev++)
            {
                int prevElement = nums[prev];
                
                if(currElement > prevElement)
                {
                    if(dp[curr]<dp[prev]+1)
                    {
                        dp[curr] = dp[prev] + 1;
                        count[curr] = count[prev];
                    }
                    else if(dp[curr]==dp[prev]+1)
                    {
                        count[curr] += count[prev];
                    }
                }
            }
        }
        
        int totalCount = 0;
        int maxLen = *max_element(begin(dp),end(dp));
        
        for(int idx = 0; idx<elements; idx++)
            totalCount += (dp[idx]==maxLen)?count[idx]:0;
        
        return totalCount;
    }
};
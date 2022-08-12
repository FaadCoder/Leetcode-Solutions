class Solution
{
    map<vector<int>, int> dp;
    
    int getMaxAndSum(vector<int> &nums, vector<int> &slots, int idx = 0)
    {
        if(idx >= nums.size())
            return 0;
        
        if(dp.count(slots))
            return dp[slots];
        
        int maxSum = 0;
        
        for(int slot = 0; slot < slots.size(); slot++)
        {
            if(slots[slot]<2)
            {
                slots[slot]++;
                
                maxSum = max(maxSum, (nums[idx] & (slot + 1)) + getMaxAndSum(nums, slots, idx+1));
                
                slots[slot]--;
            }
        }
        
        return dp[slots] = maxSum;
    }

    public:
        int maximumANDSum(vector<int> &nums, int numSlots)
        {
            vector<int> slots(numSlots, 0);
            return getMaxAndSum(nums, slots);
        }
};
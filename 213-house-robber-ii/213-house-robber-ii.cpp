class Solution {
    
    int dp[103];
    int getMaximumMoney(vector<int> &nums,int houseIdx,int totalElements)
    {
        if(houseIdx >= totalElements)
            return 0;
        
        int &cachedValue = dp[houseIdx];
        if(cachedValue != -1)
            return cachedValue;
        
        return cachedValue = max(nums[houseIdx] + getMaximumMoney(nums,houseIdx+2,totalElements),
                   getMaximumMoney(nums,houseIdx+1,totalElements));
    }
    
public:
    int rob(vector<int>& nums) {
        int totalElements = nums.size();
        if(totalElements == 1)
            return nums[0];
        if(totalElements == 2)
            return max(nums[0],nums[1]);
        
        memset(dp,-1,sizeof(dp));
        int option1 = getMaximumMoney(nums,0,totalElements-1);
        
        memset(dp,-1,sizeof(dp));
        int option2 =getMaximumMoney(nums,1,totalElements);
        
        return max(option1,option2);
    }
};
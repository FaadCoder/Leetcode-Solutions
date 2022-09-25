class Solution {
    
    
    void populateGoodDecreasingIndexes(vector<int> &nums, int k, vector<int> &isGoodDecreasing)
    {
        // Left to right decreasing
        int prev = nums[0];
        int countLen = 1;
        
        for(int idx = 1; idx < nums.size(); idx++)
        {
            if(nums[idx] <= nums[idx-1])
                countLen += 1;
            else
                countLen = 1;
            isGoodDecreasing[idx] = countLen;
        }
    }
    
    void populateGoodIncreasingIndexes(vector<int> &nums, int k, vector<int> &isGoodIncreasing)
    {
        // Right to left increasing
        
        int countLen = 1;
        
        for(int idx = nums.size() - 2; idx >= 0; idx--)
        {
            if(nums[idx] <= nums[idx+1])
                countLen += 1;
            else
                countLen = 1;
            
            isGoodIncreasing[idx] = countLen;
        }
    }
        
    
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        vector<int> isGoodDecreasing(nums.size(), 1);
        vector<int> isGoodIncreasing(nums.size(), 1);
        
        populateGoodDecreasingIndexes(nums, k, isGoodDecreasing);
        populateGoodIncreasingIndexes(nums, k, isGoodIncreasing);
        
        vector<int> ans;
        
        for(int idx = 1; idx <= nums.size() - 2; idx++)
        {
            if(isGoodIncreasing[idx + 1] >= k and isGoodDecreasing[idx - 1] >= k)
                ans.push_back(idx);
        } 
        
        return ans;
    }
};
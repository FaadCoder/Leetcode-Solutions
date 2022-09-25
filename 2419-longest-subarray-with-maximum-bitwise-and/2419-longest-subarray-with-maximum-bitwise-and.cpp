class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        if(nums.empty())
            return 0;
        
        int maxElement = *max_element(begin(nums), end(nums));
        int currentLength = 0;
        int longestLength = 0;
        
        for(int ele : nums)
        {
            if(ele == maxElement)
                currentLength += 1;
            else
                currentLength = 0;
            
            longestLength = max(currentLength, longestLength);
        }
        
        return longestLength;
        
    }
};
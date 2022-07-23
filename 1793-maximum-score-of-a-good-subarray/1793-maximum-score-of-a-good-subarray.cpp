class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int maxScore = nums[k];
        int currentMin = nums[k];
        int left = k,right = k;
        
        while(left>0 or right<nums.size()-1)
        {
            if(left==0)
                right++;
            else if(right==nums.size()-1)
                left--;
            else if(nums[left-1]<nums[right+1])
                right++;
            else 
                left--;
            currentMin = min(currentMin,min(nums[left],nums[right]));
            maxScore = max(maxScore,currentMin*(right-left+1));
        }
        
        
        return maxScore;
    }
};
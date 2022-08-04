class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        for(int idx = 0; idx<nums.size()-1; idx++)
        {
            if(idx==0)
            {
                if(nums[idx]>nums[idx+1])
                    swap(nums[idx],nums[idx+1]);
            }
            else
            {
                if((idx & 1) and nums[idx]<nums[idx+1])
                    swap(nums[idx],nums[idx+1]);
                else if(!(idx & 1) and nums[idx]>nums[idx+1])
                    swap(nums[idx],nums[idx+1]);
            }
        }
        
    }
};
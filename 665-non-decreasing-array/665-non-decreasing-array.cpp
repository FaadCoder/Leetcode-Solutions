class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       
        bool changed = false;
        
        for(int idx = 0; idx<nums.size()-1;idx++)
        {
            if(nums[idx]<=nums[idx+1])
                continue;
            if(changed)
                return false;
            
            if(idx==0 or nums[idx+1]>=nums[idx-1])
                nums[idx] = nums[idx+1];
            else
                nums[idx+1] = nums[idx];
            changed = true;
        }
        
        return true;
    }
};

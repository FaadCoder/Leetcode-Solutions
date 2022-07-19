class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peakIdx = -1;
        int numberOfElements = nums.size();
        if(numberOfElements==1)
            return;
        
        
        for(int idx=numberOfElements-2;idx>=0;idx--)
        {
            if(nums[idx]<nums[idx+1])
            {
                peakIdx = idx;
                break;
            }
        }
        
        if(peakIdx==-1)
        {
            reverse(begin(nums),end(nums));
            return;
        }
        
        int idxJustGreater = -1;
        for(int idx = numberOfElements-1; idx>=0; idx--)
        {
            if(nums[idx]>nums[peakIdx])
            {
                idxJustGreater = idx;
                break;
            }
        }
        
        swap(nums[peakIdx],nums[idxJustGreater]);
        
        reverse(nums.begin()+peakIdx+1,nums.end());
        
    }
};
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        int diff = 0;
        for(int i=1;i<size(nums);i++)
        {
            diff = nums[i]-nums[i-1]-1;
            if(diff>=k)
                return nums[i-1]+k;
            k-=diff;
        }
        return nums.back()+k;
    }
};
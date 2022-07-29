class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int minSum = 0;
        int st = 0, en = nums.size()-1;
        while(st<en)
        {
            minSum = max(minSum,nums[st++]+nums[en--]);
        }
        
        return minSum;
    }
};
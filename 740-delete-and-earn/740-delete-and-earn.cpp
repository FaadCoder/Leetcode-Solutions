class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = nums.size();
        int sum[10001] = {0};
        for(int i=0;i<n;i++)
            sum[nums[i]] += nums[i];
        for(int i=2;i<10001;i++)
        {
            sum[i] = max(sum[i-1],sum[i-2]+sum[i]);
        }
        return sum[10000];
    }
};
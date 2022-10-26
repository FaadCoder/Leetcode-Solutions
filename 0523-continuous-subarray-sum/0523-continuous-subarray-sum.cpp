class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;
            int currentSum = 0;
            mp[0] = -1;
            for (int idx = 0; idx < size(nums); idx++)
            {
                currentSum += nums[idx];
                if (k != 0)
                    currentSum %= k;

                if (mp.count(currentSum))
                {
                    if (idx - mp[currentSum] > 1)
                        return true;
                }
                else
                    mp[currentSum] = idx;
            }

            return false;
        }
};
class Solution
{
    public:
        int twoSumLessThanK(vector<int> &nums, int k)
        {
            sort(begin(nums), end(nums));
            int sum = INT_MIN;
            int start = 0, end = nums.size() - 1;
            while (start < end)
            {
                int currentSum = nums[start] + nums[end];
                if (currentSum < k)
                {
                    sum = max(sum, currentSum);
                    start += 1;
                }
                else
                {
                    end -= 1;
                }
            }
            return sum == INT_MIN ? -1 : sum;
        }
};
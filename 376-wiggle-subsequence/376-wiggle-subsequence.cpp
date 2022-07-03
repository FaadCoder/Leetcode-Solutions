class Solution
{
    int longestWiggleSequence(vector<int> &nums)
    {
        int up = 1;
        int down = 1;
        for (int idx = 1; idx < size(nums); idx++)
        {
            if (nums[idx] > nums[idx - 1])
                up = down + 1;
            else if (nums[idx] < nums[idx - 1])
                down = up + 1;
        }
        return max(up, down);
    }

    public:
        int wiggleMaxLength(vector<int> &nums)
        {
            return longestWiggleSequence(nums);
        }
};
class Solution
{
    public:
        int minDifference(vector<int> &nums)
        {
            int arraySize = nums.size();
            if (arraySize <= 4)
                return 0;

            sort(begin(nums), end(nums));

            int minDiff = INT_MAX;

           	// case 1: 3 moves = 3 biggest elements
            minDiff = min(minDiff, nums[arraySize - 4] - nums[0]);

           	// case 2: 3 moves = 2 biggest elements + 1 smallest element
            minDiff = min(minDiff, nums[arraySize - 3] - nums[1]);

           	// case 3: 3 moves = 1 biggest element + 2 smallest elements
            minDiff = min(minDiff, nums[arraySize - 2] - nums[2]);

           	// case 4: 3 moves = 3 smallest elements
            minDiff = min(minDiff, nums[arraySize - 1] - nums[3]);

            return minDiff;
        }
};
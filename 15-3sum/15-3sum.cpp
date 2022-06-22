class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            vector<vector < int>> triplets;

            if (nums.empty() or nums.size() <= 2)
                return triplets;

            int idx = 0;
            while (idx < nums.size() - 1)
            {
                int startPtr = idx + 1;
                int endPtr = nums.size() - 1;
                int target = -nums[idx];
                while (startPtr < endPtr)
                {
                    int currentSum = nums[startPtr] + nums[endPtr];
                    if (currentSum == target)
                    {
                        triplets.push_back({ nums[idx],
                            nums[startPtr],
                            nums[endPtr] });
                        while (startPtr < endPtr and nums[startPtr + 1] == nums[startPtr])
                            startPtr += 1;
                        startPtr += 1;
                        while (startPtr < endPtr and nums[endPtr - 1] == nums[endPtr])
                            endPtr -= 1;
                        endPtr -= 1;
                    }
                    else if (currentSum < target)
                        startPtr += 1;
                    else
                        endPtr -= 1;
                }
                while ((idx < nums.size() - 1) and(nums[idx + 1] == nums[idx]))
                {
                    idx++;
                }

                idx++;
            }

            return triplets;
        }
};

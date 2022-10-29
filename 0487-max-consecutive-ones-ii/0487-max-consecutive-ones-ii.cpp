class Solution
{
    public:
        int findMaxConsecutiveOnes(vector<int> &nums)
        {
            int numberOfZerosFlipped = 0;
            int runningSum = 0;
            int maxConsecutiveOnes = 0;
            int windowStart = 0;
            for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
            {
                runningSum += 1;
                numberOfZerosFlipped += (nums[windowEnd] == 0);

                while (numberOfZerosFlipped > 1 and windowStart <= windowEnd)
                {
                    if (nums[windowStart] == 0)
                        numberOfZerosFlipped -= 1;
                    runningSum -= 1;
                    windowStart += 1;
                }

                maxConsecutiveOnes = max(maxConsecutiveOnes, runningSum);
            }

            return maxConsecutiveOnes;
        }
};
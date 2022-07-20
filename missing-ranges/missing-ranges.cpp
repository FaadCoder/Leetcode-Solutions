class Solution
{
    public:
        vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
        {
            if(nums.empty())
            {
                if(lower!=upper)
                return {to_string(lower)+"->"+to_string(upper)};
                return {to_string(lower)};
            }
            
            vector<string> ans;
            int nextExpectedInteger = lower;

            for (int idx = 0; idx < nums.size(); idx++)
            {
                if (nums[idx] == nextExpectedInteger)
                {
                    nextExpectedInteger++;
                }
                else
                {
                    if (nextExpectedInteger == nums[idx] - 1)
                        ans.push_back(to_string(nextExpectedInteger));
                    else
                        ans.push_back(to_string(nextExpectedInteger) + "->" + to_string(nums[idx] - 1));
                    nextExpectedInteger = nums[idx] + 1;
                }
            }

            if (nums[nums.size() - 1] < upper)
            {
                if (nums[nums.size() - 1] + 1 == upper)
                    ans.push_back(to_string(upper));
                else
                    ans.push_back(to_string(nums[nums.size() - 1] + 1) + "->" + to_string(upper));
            }
            return ans;
        }
};
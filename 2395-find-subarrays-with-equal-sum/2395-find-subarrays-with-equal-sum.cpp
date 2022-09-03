class Solution
{
    public:
        bool findSubarrays(vector<int> &nums)
        {
            unordered_set<int> s;
            for (int i = 1; i < nums.size(); ++i)
                if (!s.insert(nums[i - 1] + nums[i]).second)
                    return true;
            return false;
        }
};
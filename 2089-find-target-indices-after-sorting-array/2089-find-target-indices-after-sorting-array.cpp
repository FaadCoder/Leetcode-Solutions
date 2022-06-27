class Solution
{
    public:
        vector<int> targetIndices(vector<int> &nums, int target)
        {
            vector<int> ans;
            int cnt = 0;
            int pos = 0;
            for (int num: nums)
            {
                cnt += (num == target);
                pos += (num < target);
            }

            while (cnt--)
            {
                ans.push_back(pos++);
            }

            return ans;
        }
};
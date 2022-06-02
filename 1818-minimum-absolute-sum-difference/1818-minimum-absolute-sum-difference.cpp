class Solution
{
    const int mod = 1e9 + 7;
    public:
        int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
        {
            set<int> treeSet(begin(nums1), end(nums1));
            int numberOfElements = nums1.size();
            int origDiff = 0;
            int maxDecrement = 0;
            for (int idx = 0; idx < numberOfElements; idx++)
            {
                int currDiff = abs(nums1[idx] - nums2[idx]);
                origDiff = (origDiff + currDiff) % mod;
                auto it = treeSet.lower_bound(nums2[idx]);
                if (it != treeSet.begin())
                    maxDecrement = max(maxDecrement, currDiff - abs(*prev(it) - nums2[idx]));
                if (it != treeSet.end())
                    maxDecrement = max(maxDecrement, currDiff - abs(*(it) - nums2[idx]));
            }
            return (origDiff - maxDecrement + mod) % mod;
        }
};
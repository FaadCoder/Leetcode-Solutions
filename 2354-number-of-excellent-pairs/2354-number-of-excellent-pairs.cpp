class Solution
{
    public:
        long long countExcellentPairs(vector<int> &nums, int k)
        {
            unordered_map<int, int> cnt;
            for (int num: unordered_set<int>(begin(nums),end(nums)))
                cnt[__builtin_popcount(num)]++;
            long long ans = 0;

            for (auto it1: cnt)
            {
                for (auto it2: cnt)
                {
                    if (it1.first + it2.first >= k)
                        ans += (it1.second) *(it2.second);
                }
            }

            return ans;
        }
};
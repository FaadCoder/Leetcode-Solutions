class Solution
{
    public:
        long long countBadPairs(vector<int> &a, long cnt = 0)
        {
            unordered_map<int, int> mp;
            for (int i = 0; i < size(a); i++)
            {
                cnt += i - mp[i - a[i]];
                mp[i - a[i]]++;
            }
            return cnt;
        }
};
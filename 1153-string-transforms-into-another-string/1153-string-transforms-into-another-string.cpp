class Solution
{
    public:
        bool canConvert(string s1, string s2)
        {
            if (s1 == s2) return true;
            unordered_map<char, char> dp;
            for (int i = 0; i < s1.length(); ++i)
            {
                if (dp[s1[i]] != NULL && dp[s1[i]] != s2[i])
                    return false;
                dp[s1[i]] = s2[i];
            }
            return set(s2.begin(), s2.end()).size() < 26;
        }
};
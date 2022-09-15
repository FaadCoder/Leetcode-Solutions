class Solution
{
    public:
        int lengthOfLongestSubstringTwoDistinct(string s)
        {
            unordered_map<char, int> freqHashMap;
            int start = 0;
            int longestSubstring = 0;

            for (int end = 0; end < s.length(); end++)
            {
                freqHashMap[s[end]]++;
                while (freqHashMap.size() > 2 and start <= end)
                {
                    freqHashMap[s[start]]--;
                    if (freqHashMap[s[start]] == 0)
                        freqHashMap.erase(s[start]);
                    start++;
                }
                longestSubstring = max(longestSubstring, end - start + 1);
            }

            return longestSubstring;
        }
};
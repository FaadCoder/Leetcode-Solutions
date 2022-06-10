class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_map<char, int> letterFrequencyMap;
            int windowStart = 0;
            int stringSize = (int) s.length();
            int longestSubstringLength = 0;
            for (int windowEnd = 0; windowEnd < stringSize; windowEnd++)
            {
                letterFrequencyMap[s[windowEnd]]++;
                while (letterFrequencyMap[s[windowEnd]] > 1 and windowStart <= windowEnd)
                {
                    letterFrequencyMap[s[windowStart]] -= 1;
                    if (letterFrequencyMap[s[windowStart]] <= 0)
                        letterFrequencyMap.erase(s[windowStart]);
                    windowStart += 1;
                }
                longestSubstringLength = max(longestSubstringLength, windowEnd - windowStart + 1);
            }
            return longestSubstringLength;
        }
};
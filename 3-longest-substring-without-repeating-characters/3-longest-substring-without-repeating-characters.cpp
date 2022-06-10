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
                char charAtWindowEnd = s[windowEnd];
                letterFrequencyMap[charAtWindowEnd]++;

                while (letterFrequencyMap[s[windowEnd]] > 1 and windowStart <= windowEnd)
                {
                    char charAtWindowStart = s[windowStart];
                    letterFrequencyMap[charAtWindowStart] -= 1;

                    if (letterFrequencyMap[charAtWindowStart] <= 0)
                        letterFrequencyMap.erase(charAtWindowStart);

                    windowStart += 1;
                }
                longestSubstringLength = max(longestSubstringLength, windowEnd - windowStart + 1);
            }
            return longestSubstringLength;
        }
};
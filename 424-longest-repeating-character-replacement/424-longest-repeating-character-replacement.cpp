class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            unordered_map<char, int> frequencyMap;
            int longestSubstringWithSameLetter = 0;
            int windowStart = 0;
            int maxCharacterCount = 0;
            for (int windowEnd = 0; windowEnd < s.length(); windowEnd++)
            {
                char charAtWindowEnd = s[windowEnd];
                frequencyMap[charAtWindowEnd]++;
                maxCharacterCount = max(maxCharacterCount, frequencyMap[charAtWindowEnd]);
                int windowSize = windowEnd - windowStart + 1;

                while (windowSize - maxCharacterCount > k)
                {
                    char charAtWindowStart = s[windowStart];
                    frequencyMap[charAtWindowStart]--;
                    maxCharacterCount = max(maxCharacterCount, frequencyMap[charAtWindowEnd]);
                    windowStart++;
                    windowSize = windowEnd - windowStart + 1;
                }

                windowSize = windowEnd - windowStart + 1;
                longestSubstringWithSameLetter = max(longestSubstringWithSameLetter, windowSize);
            }

            return longestSubstringWithSameLetter;
        }
};
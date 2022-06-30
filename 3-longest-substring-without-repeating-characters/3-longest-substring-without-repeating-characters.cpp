class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            
            unordered_map<char, int> frequencyHashMap;

            int windowStart = 0;
            int longestLength = 0;

            for (int windowEnd = 0; windowEnd < s.length(); windowEnd++)
            {
                char charAtWindowEnd = s[windowEnd];
                frequencyHashMap[charAtWindowEnd]++;
                
                while (frequencyHashMap[charAtWindowEnd] > 1)
                {
                    char charAtWindowStart = s[windowStart];
                    frequencyHashMap[charAtWindowStart]--;
                    
                    if (frequencyHashMap[charAtWindowStart] <= 0)
                        frequencyHashMap.erase(charAtWindowStart);
                    
                    windowStart++;
                }
                longestLength = max(longestLength, windowEnd - windowStart + 1);
            }

            return longestLength;
        }
};
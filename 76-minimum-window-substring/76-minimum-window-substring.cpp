class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if (s.length() < t.length())
                return "";
            if (s == t)
                return s;

            int start = 0;
            unordered_map<char, int> freqHashMap;
            for (char &ch: t)
                freqHashMap[ch]++;

            int count = freqHashMap.size();

            int windowLength = INT_MAX;
            int windowStart = -1;
            for (int end = 0; end < s.length(); end++)
            {
                if (freqHashMap.count(s[end]))
                {
                    freqHashMap[s[end]]--;
                    if (freqHashMap[s[end]] == 0)
                        count--;
                }

                while (count == 0 and start <= end)
                {
                    if (end - start + 1 < windowLength)
                    {
                        windowLength = end - start + 1;
                        windowStart = start;
                    }
                    if (freqHashMap.count(s[start]))
                    {
                        if (freqHashMap[s[start]] == 0)
                            count++;
                        freqHashMap[s[start]]++;
                    }
                    start++;
                }
            }

            return (windowStart != -1) ? s.substr(windowStart, windowLength) : "";
        }
};
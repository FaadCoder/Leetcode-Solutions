class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqMap;
        
        for(char &ch : t)
            freqMap[ch] += 1;
        
        int totalCharactersInT = freqMap.size();

        int windowLen = s.length() + 1;
        int windowStart = 0;
        int startAns = -1;
        
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            char currentChar = s[windowEnd];
            
            if(freqMap.count(currentChar))
            {
                freqMap[currentChar] -= 1;
                if(freqMap[currentChar] == 0)
                    totalCharactersInT -= 1;
            }
            while(totalCharactersInT == 0 and windowStart <= windowEnd)
            {
                if(windowLen > windowEnd - windowStart + 1)
                {
                    windowLen = windowEnd - windowStart + 1;
                    startAns = windowStart;
                }
                
                if(freqMap.count(s[windowStart]))
                {
                    if(freqMap[s[windowStart]] == 0)
                        totalCharactersInT += 1;
                    freqMap[s[windowStart]] += 1;
                }
                windowStart += 1;
            }
        }
        return (startAns != -1) ? s.substr(startAns, windowLen) : "";
    }
};
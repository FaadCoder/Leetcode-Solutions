class Solution {
    
public:
    int characterReplacement(string s, int k) {
        int windowStart = 0;
        
        vector<int> frequency(26, 0);
        
        int maxFrequency = 0;
        int len = 0;
        
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            maxFrequency = max(maxFrequency, ++frequency[s[windowEnd] - 'A']);
            
            while(windowEnd - windowStart + 1 - maxFrequency > k)
            {
                frequency[s[windowStart] - 'A'] -= 1;
                windowStart += 1;
            }
            
            len = max(len, windowEnd - windowStart + 1);
        }
        
        return len;
    }
};
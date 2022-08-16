class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        
        for(char &ch: s)
            freq[ch-'a'] += 1;
        
        for(int idx = 0; idx < s.length(); idx++)
        {
            int currChar = (s[idx] - 'a');
            
            if(freq[currChar] == 1)
                return idx;
        
        }
        return -1;
    }
};
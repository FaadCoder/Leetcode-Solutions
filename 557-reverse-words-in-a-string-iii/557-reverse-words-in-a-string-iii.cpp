class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s), end(s));
        
        int idx = 0;
        while(idx < s.length())
        {
            int j = idx;
            
            while(j < s.length() and s[j] != ' ')
                j += 1;
            
            int nextCharIdx = j + 1;
            j-=1;
            
            while(idx<=j)
            {
                swap(s[idx], s[j]);
                idx += 1;
                j -= 1;
            }
            
            idx = nextCharIdx;
        }
        
        reverse(begin(s), end(s));
        
        return s;
    }
};
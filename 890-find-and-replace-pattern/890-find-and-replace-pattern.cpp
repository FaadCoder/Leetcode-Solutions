class Solution {
    
    string getMappedString(string &str)
    {
        int freq[26] = {0};
        int previousIndex = 1;
        string mappedString;
        
        for(char &ch:str)
        {
            if(freq[ch-'a'])
            {
                mappedString.push_back(freq[ch-'a']+'0');        
            }
            else
            {
                mappedString.push_back(previousIndex + '0');
                freq[ch-'a'] = previousIndex;
                previousIndex++;
            }
        }
        
        return mappedString;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        string newMappedPattern = getMappedString(pattern);
        vector<string> matchingWords;
        
        for(string &word:words)
        {
            if(getMappedString(word) == newMappedPattern)
                matchingWords.push_back(word);
        }
        
        return matchingWords;
    }
};
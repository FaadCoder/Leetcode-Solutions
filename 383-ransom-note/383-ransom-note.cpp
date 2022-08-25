class Solution {
    
    vector<int> getStringHash(string &str)
    {
        vector<int> hash(26, 0);
        
        for(char &ch : str)
            hash[ch - 'a'] += 1;
        
        return hash;
    }
    
    bool compareHashes(vector<int> hash1, vector<int> hash2)
    {
        for(int ch = 0; ch < 26; ch++)
        {
            if(hash2[ch] < hash1[ch])
                return false;
        }
        
        return true;
    }
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        return compareHashes(getStringHash(ransomNote), getStringHash(magazine));
    }
};
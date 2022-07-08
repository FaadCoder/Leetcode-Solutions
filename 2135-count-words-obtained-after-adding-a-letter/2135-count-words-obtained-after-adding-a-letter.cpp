class Solution {
    
    int getHash(string &word)
    {
        int hash = 0;
        for(auto &ch:word)
        {
            hash += (1<<(ch-'a'));
        }
        
        return hash;
    }
    
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> hashSet;
        
        for(string &word:startWords)
            hashSet.insert(getHash(word));
        
        int cnt = 0;
        
        for(string &target:targetWords)
        {
            int targetHash = getHash(target);
            for(char &ch:target)
            {
                if(hashSet.count(targetHash - (1<<(ch-'a'))))
                {
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};
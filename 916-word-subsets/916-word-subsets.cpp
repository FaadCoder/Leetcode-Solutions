class Solution {
    vector<int> getFreqMap(string &str)
    {
        vector<int> freq(26,0);
        
        for(auto ch:str)
            freq[ch-'a']++;
        
        return freq;
    }
    
    bool isSuperSet(vector<int> &currFreq,vector<int> &maxFreq)
    {
        for(int ch = 0; ch<26; ch++)
        {
            if(currFreq[ch]<maxFreq[ch])
                return false;
        }
        return true;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFrequencyMap(26,0);
        
        for(string &word:words2)
        {
            vector<int> currFreq = getFreqMap(word);
            for(int ch = 0; ch<26; ch++)
                maxFrequencyMap[ch] = max(maxFrequencyMap[ch],currFreq[ch]);
        }
        
        vector<string> ans;
        for(string &word:words1)
        {
            vector<int> currFreq = getFreqMap(word);
            if(isSuperSet(currFreq,maxFrequencyMap))
                ans.push_back(word);
        }
        
        return ans;
    }
};
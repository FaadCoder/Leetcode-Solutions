class WordDistance {
    unordered_map<string,vector<int>> hashMap;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int idx=0;idx<size(wordsDict);idx++)
            hashMap[wordsDict[idx]].push_back(idx);
    }
    
    int shortest(string word1, string word2) {
        int shortestDistance = INT_MAX;
        int i=0,j=0;
        while(i<hashMap[word1].size() and j<hashMap[word2].size())
        {
            shortestDistance = min(abs(hashMap[word1][i]-hashMap[word2][j]),shortestDistance);
            if(hashMap[word1][i]<hashMap[word2][j])
                i++;
            else
                j++;
        }
        return shortestDistance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
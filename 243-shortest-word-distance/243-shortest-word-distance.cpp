class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,vector<int>> hashMap;
 
        for(int idx=0;idx<size(wordsDict);idx++)
            hashMap[wordsDict[idx]].push_back(idx);
        
        int i = 0;
        int j = 0;
        
        int dis = INT_MAX;
        
        while(i<hashMap[word1].size() and j<hashMap[word2].size())
        {
            dis = min(dis,abs(hashMap[word1][i]-hashMap[word2][j]));
            if(hashMap[word1][i]>hashMap[word2][j])
                j++;
            else if(hashMap[word1][i]<hashMap[word2][j])
                i++;
            else
                i++,j++;
        }
        
        return dis;
    }
};
class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(char ch:s)
            freq[ch-'a']++;
        
        unordered_set<int> freqVisited;
        int minDel = 0;
        for(char ch='a'; ch<='z'; ch++)
        {
            int frequency = freq[ch-'a'];
            while(frequency > 0 and freqVisited.count(frequency))
            {
                minDel += 1;
                frequency -= 1;
            }
            freqVisited.insert(frequency);
        }
        
        return minDel;
    }
};
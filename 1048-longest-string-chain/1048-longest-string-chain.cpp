class Solution {
public:
    int longestStrChain(vector<string>& words) {
    
        // Lambda function for Custom Sorting Comparator.
        auto sortingComparator = [&](string &word1,string &word2){
            return word1.length() < word2.length();
        };
        
        // Apply sorting to words vector on the basis of Lengths.
        sort(words.begin(),words.end(),sortingComparator);
        
        // HashMap to keep track of visited words and values.
        unordered_map<string,int> stringCache;
        
        int longestStringChain = 0;
        
        // Go through each word in words, and try to form longest chain.
        for(string word:words)
        {
            int wordLen = word.length();
            for(int idx = 0; idx<wordLen; idx++)
            {
                string stringExcludingCurrentIdx = word.substr(0,idx) + word.substr(idx+1);
                stringCache[word] = max(stringCache[word],
                                        stringCache.count(stringExcludingCurrentIdx) ? stringCache[stringExcludingCurrentIdx] + 1 : 1);
            }
            longestStringChain = max(longestStringChain, stringCache[word]);
        }
        return longestStringChain;
    }
};
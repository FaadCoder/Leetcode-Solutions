/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int getMatches(string &word1,string &word2)
    {
        int matches = 0;
        for(int i=0;i<word1.length();i++)
            matches += (word1[i]==word2[i]);
        return matches;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i=0;i<10;i++)
        {
            int randIdx = rand()%(wordlist.size());
            int matches = master.guess(wordlist[randIdx]);
            vector<string> trimmedWordlist;
            
            for(string &word:wordlist)
            {
                if(matches == getMatches(word,wordlist[randIdx]))
                    trimmedWordlist.push_back(word);
            }
            
            wordlist = trimmedWordlist;
        }
    }
};
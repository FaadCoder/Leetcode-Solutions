class Solution
{
    public:
        int countPrefixes(vector<string> &words, string s)
        {
            int prefixCount = 0;

            for (string &word: words)
            {
                if (word.length() > s.length())
                    continue;
                prefixCount += (s.substr(0, word.length()) == word);
                    
            }

            return prefixCount;
        }
};
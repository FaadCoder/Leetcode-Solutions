struct Pair
{
    const string &word;
    int index;

    Pair(const string &_word, int _index):word(_word),index(_index)
    {
    }
};

class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            unordered_map<char, vector < Pair>> charToWordsHashMap;
            int index = 0;
            for (string &word: words)
                charToWordsHashMap[word[0]].push_back(Pair(word, 0));

            int matchingSubsequences = 0;

            for (char &ch: s)
            {
                if (charToWordsHashMap.count(ch))
                {
                    vector<Pair> wordsStartingWithCurrentChar = charToWordsHashMap[ch];
                    charToWordsHashMap[ch].clear();

                    for (Pair &wordPair: wordsStartingWithCurrentChar)
                    {
                        wordPair.index++;
                        if (wordPair.index == wordPair.word.length())
                            matchingSubsequences += 1;
                        else
                        {
                            charToWordsHashMap[wordPair.word[wordPair.index]].push_back(wordPair);
                        }
                    }
                }
            }

            return matchingSubsequences;
        }
};
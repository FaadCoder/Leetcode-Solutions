struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    string word;
    TrieNode()
    {
        children.clear();
        word = "";
    }
};

class Trie
{
    public:
        void addWord(TrieNode *root, const string &word)
        {
            for (const char &ch: word)
            {
                if (!root->children.count(ch))
                    root->children[ch] = new TrieNode();
                root = root->children[ch];
            }
            root->word = word;
        }

    void populateWordsInLexicographicalOrder(TrieNode *root, vector<string> &res, int k)
    {
        if (!root)
            return;

        if (!root->word.empty())
            res.push_back(root->word);

        if (res.size() == k)
            return;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (root->children.count(ch))
                populateWordsInLexicographicalOrder(root->children[ch], res, k);
        }
    }
};

class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            Trie trie;
            vector<string> topKFrequentWords;
            unordered_map<string, int> frequencyMap;
            vector<TrieNode*> frequencyBuckets;

            for (string &word: words)
                frequencyMap[word]++;

            for (int i = 0; i <= words.size(); i++)
                frequencyBuckets.push_back(new TrieNode());

            for (auto &it: frequencyMap)
                trie.addWord(frequencyBuckets[it.second], it.first);

            for (int i = words.size(); i >= 1; i--)
            {
                trie.populateWordsInLexicographicalOrder(frequencyBuckets[i], topKFrequentWords, k);
                if (topKFrequentWords.size() == k)
                    break;
            }

            return topKFrequentWords;
        }
};
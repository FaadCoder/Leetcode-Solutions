struct Node
{
    public: int idx;
    const string &word;
    Node(const string &_word, int _idx): word(_word),
    idx(_idx) {}
};
class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            vector<Node> mp[26];
            int ans = 0;

            for (string &word: words)
                mp[word[0] - 'a'].push_back(Node(word, 0));

            for (char &ch: s)
            {
                vector<Node> values = mp[ch - 'a'];
                mp[ch - 'a'].clear();

                for (Node &value: values)
                {
                    value.idx += 1;
                    if (value.idx == value.word.size())
                        ans += 1;
                    else
                        mp[value.word[value.idx] - 'a'].push_back(value);
                }
            }

            return ans;
        }
};
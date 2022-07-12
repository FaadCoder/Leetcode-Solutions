class UnionFind
{
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
    public:
        UnionFind(vector<string> &s1, vector<string> &s2)
        {
            for (string &str: s1)
                parent[str] = str, size[str] = 1;
            for (string &str: s2)
                parent[str] = str, size[str] = 1;
        }

    string findParent(string & child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    void unionSets(string &s1, string &s2)
    {
        s1 = findParent(s1);
        s2 = findParent(s2);
        if (s1 == s2)
            return;
        if (size[s1] < size[s2])
            swap(s1, s2);
        parent[s2] = s1;
        size[s1] += size[s2];
    }

    bool isConnected(string &s1, string &s2)
    {
        return (findParent(s1) == findParent(s2));
    }
};

class Solution
{

    public:
        bool areSentencesSimilarTwo(vector<string> &s1, vector<string> &s2, vector< vector< string>> &similarPairs)
        {
            if (s1.size() != s2.size())
                return false;
            UnionFind unionFind(s1, s2);
            for (auto &similarPair: similarPairs)
                unionFind.unionSets(similarPair[0], similarPair[1]);

            for (int idx = 0; idx < s1.size(); idx++)
            {
                if (s1[idx] != s2[idx] and!unionFind.isConnected(s1[idx], s2[idx]))
                {
                    return false;
                }
            }
            return true;
        }
};
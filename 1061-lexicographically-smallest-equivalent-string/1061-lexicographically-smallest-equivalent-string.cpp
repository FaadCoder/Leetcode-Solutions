class UnionFind
{
    private:
        unordered_map<char, char> parent;
    public:
        UnionFind()
        {
            parent.clear();
            for (char ch = 'a'; ch <= 'z'; ch++)
                parent[ch] = ch;
        }

    char findParent(char child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    void unionSets(char set1, char set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);
        if (set1 == set2)
            return;
        if (set1 > set2)
            swap(set1, set2);
        parent[set2] = set1;
    }
};

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr)
        {
            UnionFind unionFind;
            for (int idx = 0; idx < s1.length(); idx++)
                unionFind.unionSets(s1[idx], s2[idx]);

            for (char &ch: baseStr)
            {
                ch = unionFind.findParent(ch);
            }

            return baseStr;
        }
};
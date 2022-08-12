struct TrieNode
{
    string content;
    map<string, TrieNode*> children;

    TrieNode() {}
};

class Trie
{
    private:
        TrieNode * root;

    public:

        Trie()
        {
            root = new TrieNode();
        }

    vector<string> getStrs(string & path)
    {
        stringstream ss(path);
        string temp;
        vector<string> strs;

        while (getline(ss, temp, '/'))
        {
            if (!temp.empty())
                strs.push_back(temp);
        }
        return strs;
    }

    void addPath(string &path, string content = "")
    {
        vector<string> strs = getStrs(path);
        auto temp = root;
        for (string &str: strs)
        {
            if (!temp->children.count(str))
                temp->children[str] = new TrieNode();

            temp = temp->children[str];
        }
        if (content.length())
            temp->content += content;
    }

    vector<string> evaluateLS(string & path)
    {
        vector<string> strs = getStrs(path);
        vector<string> ans;

        auto temp = root;
       
        for (string &str: strs)
            temp = temp->children[str];
       
        if (!temp->content.empty())
            return { strs.back() };

        for (auto &it: temp->children)
            ans.push_back(it.first);

        return ans;
    }

    string getFileContent(string & path)
    {
        vector<string> strs = getStrs(path);
        auto temp = root;

        for (string &str: strs)
            temp = temp->children[str];

        return temp->content;
    }
};

class FileSystem
{
    Trie trie;
    public:
        FileSystem() {}

    vector<string> ls(string path)
    {
        return trie.evaluateLS(path);
    }

    void mkdir(string path)
    {
        trie.addPath(path);
    }

    void addContentToFile(string filePath, string content)
    {
        trie.addPath(filePath, content);
    }

    string readContentFromFile(string filePath)
    {
        return trie.getFileContent(filePath);
    }
};

/**
 *Your FileSystem object will be instantiated and called as such:
 *FileSystem* obj = new FileSystem();
 *vector<string> param_1 = obj->ls(path);
 *obj->mkdir(path);
 *obj->addContentToFile(filePath,content);
 *string param_4 = obj->readContentFromFile(filePath);
 */
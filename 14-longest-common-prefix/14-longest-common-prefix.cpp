struct TrieNode{
    int numberOfWordsEnding;
    unordered_map<char,TrieNode *> children;
    TrieNode()
    {
        numberOfWordsEnding = 0;
        children.clear();
    }
};

class Trie{
private:
 TrieNode *root;
public:  
    Trie()
    {
        root = new TrieNode();
    }
    
    void addWord(string &word)
    {
        TrieNode *currPtr = root;
        for(char &ch:word)
        {
            if(!currPtr->children.count(ch))
                currPtr->children[ch] = new TrieNode();
            currPtr = currPtr->children[ch];
            currPtr->numberOfWordsEnding += 1;
        }
    }
    
    string getLongestCommonPrefix(string &str,int cnt)
    {
        int idx = 0;
        TrieNode *currPtr = root->children[str[idx]];
        
        string maxString = "";
        while(idx<str.length() and (currPtr->numberOfWordsEnding == cnt))
        {
            maxString.push_back(str[idx]);
            idx+=1;
            currPtr = currPtr->children[str[idx]];
        }
        
        return maxString;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        Trie trie;
        for(string &str:strs)
        {
            trie.addWord(str);
        }
        string maxString = *max_element(strs.begin(),strs.end());
        
        if(maxString.empty())
            return "";
        
        return trie.getLongestCommonPrefix(maxString,strs.size());
    }
};
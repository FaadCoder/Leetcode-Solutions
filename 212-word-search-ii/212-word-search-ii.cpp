struct TrieNode{
    unordered_map<char,TrieNode *> child;
    bool isLeaf;
    TrieNode()
    {
        isLeaf = false;
        child.clear();
    }
    
    bool containsLink(char ch)
    {
        return child.count(ch);
    }
    
    void addLink(char ch)
    {
        child[ch] = new TrieNode();
    }
};

class Trie{
private:
    TrieNode *root;
public:  
    Trie(vector<string> &words)
    {
        root = new TrieNode();
        for(string word:words)
            addWord(word);
    }
    
    void addWord(string &str)
    {
        TrieNode *ptr = root;
        for(char ch:str)
        {
            if(!ptr->containsLink(ch))
            {
                ptr->addLink(ch);
            }
            ptr=ptr->child[ch];
        }
        ptr->isLeaf = true;
    }
    
    TrieNode *getRootNode()
    {
        return root;
    }
};

class Solution {
    set<string> vis;
    int row,col;
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode *root,string word="")
    {
        if(i<0 or i>=row or j<0 or j>=col or board[i][j]==' ' or !root->containsLink(board[i][j]))
            return;
        char ch = board[i][j];
        board[i][j] = ' ';
        root = root->child[ch];
        word+=ch;
        if(root->isLeaf)
            vis.insert(word);
        dfs(board,i+1,j,root,word);
        dfs(board,i,j+1,root,word);
        dfs(board,i-1,j,root,word);
        dfs(board,i,j-1,root,word);
        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie dict(words);
        TrieNode *root = dict.getRootNode();
        row = board.size();
        col = board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(root->containsLink(board[i][j]))
                {
                    dfs(board,i,j,root);
                }
            }
        }
        vector<string> wordResult(vis.begin(),vis.end());
        return wordResult;
    }
};


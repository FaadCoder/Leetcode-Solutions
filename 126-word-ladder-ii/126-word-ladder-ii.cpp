class Solution
{
    public:
        unordered_map<string, vector < string>> adjList;
    vector<string> currPath;
    vector<vector < string>> shortestPaths;

    vector<string> findNeighbors(string &word, unordered_set<string> &wordList)
    {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++)
        {
            char oldChar = word[i];

           	// replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

               	// skip if the character is same as original or if the word is not present in the
               	// wordList
                if (c == oldChar || !wordList.count(word))
                {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string &source, string &destination)
    {
       	// store the path if we reached the endWord
        if (source == destination)
        {
            shortestPaths.push_back(vector<string> (currPath.rbegin(), currPath.rend()));
        }
        for (int i = 0; i < adjList[source].size(); i++)
        {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void bfs(string &beginWord, string &endWord, unordered_set<string> &wordList)
    {
        queue<string> q;
        q.push(beginWord);

       	// remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end())
        {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;

        while (!q.empty())
        {
           	// visited will store the words of current layer
            vector<string> visited;

            for (int i = q.size() - 1; i >= 0; i--)
            {
                string currWord = q.front();
                q.pop();

               	// findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word: neighbors)
                {
                    visited.push_back(word);
                   	// add the edge from word to currWord in the list
                    adjList[word].push_back(currWord);

                    if (isEnqueued.find(word) == isEnqueued.end())
                    {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
           	// removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++)
            {
                if (wordList.find(visited[i]) != wordList.end())
                {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }

    vector<vector < string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
       	// copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
       	// build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);

       	// every path will start from the endWord
        currPath = { endWord
        };
       	// traverse the DAG to find all the paths between endWord and beginWord
        backtrack(endWord, beginWord);

        return shortestPaths;
    }
};
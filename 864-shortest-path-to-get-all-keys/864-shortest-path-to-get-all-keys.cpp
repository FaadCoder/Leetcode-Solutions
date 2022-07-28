struct Node
{
    int row, col, currentKeysMask;

};

class Solution
{
    int rows, cols;

    vector<pair<int, int>> dirs = {
		{ 1,
            0 },
        { -1,
            0 },
        { 0,
            1 },
        { 0,
            -1 }
    };

    string getString(int row, int col, int currentKeysMask)
    {
        return to_string(row) + "|" + to_string(col) + "|" + to_string(currentKeysMask);
    }

    public:
        int shortestPathAllKeys(vector<string> &grid)
        {
            rows = grid.size();
            cols = grid[0].length();

            pair<int, int> startPosition;
            int originalKeysMask = 0;

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (grid[row][col] == '@')
                        startPosition = { row,
                            col
                        };
                    if (grid[row][col] >= 'a'
                        and grid[row][col] <= 'z')
                        originalKeysMask |= (1 << (grid[row][col] - 'a'));
                }
            }

            auto isValid =[& ](int row, int col)
            {
                return row >= 0 and row < rows and col >= 0 and col < cols and grid[row][col] != '#';
            };

            int level = 0;

            queue<Node> bfsQueue;
            bfsQueue.push(Node
            {
                startPosition.first, startPosition.second, 0 });

            unordered_set<string> vis;
            vis.insert(getString(startPosition.first, startPosition.second, 0));

            while (!bfsQueue.empty())
            {
                int size = bfsQueue.size();
                while (size--)
                {
                    auto front = bfsQueue.front();
                    bfsQueue.pop();
                    int row = front.row;
                    int col = front.col;
                    int currentKeysMask = front.currentKeysMask;
                    
                    if (grid[row][col] >= 'a'
                                and grid[row][col] <= 'z')
                    {
                        currentKeysMask |= (1 << (grid[row][col] - 'a'));
                    }

                    
                    if (currentKeysMask == originalKeysMask)
                        return level;

                    for (auto[x, y]: dirs)
                    {
                        int nextRow = row + x;
                        int nextCol = col + y;

                        string str = getString(nextRow, nextCol, currentKeysMask);
                        if (isValid(nextRow, nextCol))
                        {
                            if (grid[nextRow][nextCol] >= 'A'
                                and grid[nextRow][nextCol] <= 'Z'
                                and((currentKeysMask >> (grid[nextRow][nextCol] - 'A')) & 1) == 0)
                            {
                                continue;
                            }
                            if(!vis.count(str))
                            {
                                vis.insert(str);
                                bfsQueue.push(Node
                                {
                                    nextRow,
                                    nextCol,
                                    currentKeysMask 
                                });
                            }
                        }
                    }
                }
                level += 1;
            }

            return -1;
        }
};